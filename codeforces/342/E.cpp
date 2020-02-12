#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
const int MX_LG = 20;

set<int>edg[MAX];

int lvl[MAX] , table[MAX][MX_LG]  , comp , sz[MAX] , centree[MAX];
int n , m;

int ans[MAX];

void dfs1(int node , int p , int l ) {
    
    lvl[node] = l;
    table[node][0] = p;
    
    for(auto x : edg[node]) {
        
        if(x == p ) continue;
        dfs1(x , node , l+1);
    }
}

void buildTable() {

    for(int i = 1 ; i < MX_LG ; i++ ) {
        
        for(int j = 1; j <=n ; j++ ) {
            
            if(table[j][i-1] == -1  ) continue;
            
            table[j][i] = table[ table[j][i-1] ][i-1];
        }
    }
}

void visit(int node , int p) {
    
    comp++;
    sz[node] = 1;
    
    for(auto x : edg[node]) {
        
        if(x == p) continue;
        visit(x , node);
        sz[node] += sz[x];
    }
}

int getCentroid(int node , int p) {
    
    for(auto x : edg[node]) {
        
        if(x == p ) continue;
        
        if( 2*sz[x] > comp) return getCentroid(x , node);
    }
    return node;
}


void decompose(int node , int p) {

    comp = 0;
    visit(node , p);
    
    int centroid = getCentroid(node , p);
    
    centree[centroid] = p;
    
    for(auto x : edg[centroid]) {
        
        edg[x].erase(centroid);
        decompose(x , centroid);
    }
    edg[centroid].clear();
    
}

int query(int u ,int  v) {

    if(lvl[u] < lvl[v]) swap( u ,v );
    
    while(lvl[u] > lvl[v]) {
        
        int logDst = log2( lvl[u] - lvl[v] ) ;
        u = table[u][logDst];
    }
    if( u == v ) return u;
    
    for(int logVal = log2(lvl[u]) ; logVal >=0 ; logVal-- ) {
        
        if(table[u][logVal] != table[v][logVal] && table[u][logVal] != -1) {
            
            u = table[u][logVal];
            v = table[v][logVal];
        }
    }
    return table[u][0];
}

int dist(int u , int v) {
    
    int lca = query(u , v);
    return lvl[u] + lvl[v] - 2*lvl[lca];
}

void update(int node) {
    
    int x = node ;
    while(x != -1) {
        
        ans[x] = min(ans[x] , dist(x , node));
        x = centree[x];
    }
}

int query(int node) {
    
    int x = node , ret = INF;
    
    while(x != -1) {
        ret = min(ret , dist(x , node) + ans[x] ) ;
        x = centree[x];
    }
    return ret;
}


int main()
{
    fastRead;
    
    cin>>n>>m;
    for(int i =1 ; i < n ;i++ ) {
        int u , v;
        cin>>u>>v;
        
        edg[u].insert(v);
        edg[v].insert(u);
    }
    
    memset(table, -1 , sizeof table);
    dfs1(1 , -1 , 1);
    buildTable();
    
    
    decompose(1 , -1);

    for(int i =1 ; i <=n ; i++ ) ans[i] = INF;
    update(1);

    while(m--) {
        
        int typ , node;
        cin>>typ>>node;
        if(typ == 1) update(node);
        else cout<<query(node)<<'\n';
    }
    return 0;
    
}