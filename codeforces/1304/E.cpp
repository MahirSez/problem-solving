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


const int MAX = 1e5 + 5;
int table[MAX][20] , t , par[MAX] , lvl[MAX] , n ,q, tst;
vector<int>edg[MAX];

void dfs(int node ,int parent ,int level) {
    lvl[node] = level;
    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if( x != parent) {
            par[x] = node;
            dfs(x , node , level+1);
        }
    }
}

void build() {

    memset( table , -1 ,sizeof table);
    for(int i =1 ; i <=n ; i++ ) {
        table[i][0] = par[i];
    }

    for(int j =1 ; (1 << j) < n ; j++ ) {
        for(int i =1 ; i <= n ;i++ ) {
            if( table[i][j-1] != -1) {
                table[i][j] = table[table[i][j-1]][j-1];
            }
        }
    }
}

int query(int u , int v) {

    if( lvl[u] < lvl[v] ) swap(u,v);
    while( lvl[u] > lvl[v] ) {
        int logDist = log2(lvl[u] - lvl[v]);
        u = table[u][logDist];
    }

    if( u == v) return u;

    int logVal = log2(lvl[u]);
    for(; logVal >=0 ; logVal--) {
        if( table[u][logVal] !=-1 && table[u][logVal] != table[v][logVal]) {
            u = table[u][logVal];
            v = table[v][logVal];
        }
    }
    return par[u];
}


int dist(int u , int v) {

    
    int lca = query(u , v);
    return lvl[u] + lvl[v] - 2*lvl[lca];
}


int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n-1 ; i++ ) {
        
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    dfs(1, -1 , 1);
    build();
    
//    for(int i =1;  i <=n ; i++) cout<<lvl[i]<<" ";
//    cout<<'\n';
//    
    int q;
    cin>>q;
    while(q-- ) {
        
        int x , y , a , b , k;
        cin>>x>>y>>a>>b>>k;
        
        bool ok = 0;
        
        int dstab = dist(a , b);
        
        if(dstab <= k && (k - dstab)%2 == 0 ) ok = 1;
        
        
        int dstxy = dist(x , y);
        
        int clen = dstxy + 1;
        
//        cout<<k<<" "<<clen<<'\n';
        
        
        int dstax = dist(a , x);
        int dstay = dist(a , y);
        
        int dstbx = dist( b , x);
        int dstby = dist(b , y);
        
        int tmp = min(dstax + dstby , dstay + dstbx) + 1;
        
        if(tmp <=k && (k - tmp)%2 == 0 ) ok = 1;
        
        if( (k-tmp)%2  && (clen%2) &&  tmp + clen <= k  ) ok = 1;
            
        if(ok ) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    
    
    return 0;
}


