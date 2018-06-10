#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m , par[MAX] , lvl[MAX] ;
int table[MAX][20] , sub[MAX];
vector<int>edg[MAX];

void dfs(int node ,int parent , int lev) {
    lvl[node] = lev;
    sub[node] = 1;
    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if( x == parent) continue;
        par[x] = node;
        dfs(x ,node , lev+1);
        sub[node] += sub[x];
    }
}

void build() {
    memset( table, -1 , sizeof table);
    for(int i =1; i<=n ; i++ ) table[i][0] = par[i];

    for(int j = 1 ; (1<<j) <= n ;j++ ) {
        for(int i = 1 ; i<= n ; i++ ) {
            if( table[i][j-1] != -1) {
                table[i][j] = table[ table[i][j-1] ][ j-1 ];
            }
        }
    }
}

int get(int node ,int up) {
    while( up ) {
        int rise = log2(up);
        node = table[node][rise];
        up -= (1<<rise);
    }
    return node;
}


int solve(int u , int v) {
    if( u == v) return n;

    if(lvl[u] < lvl[v]) swap(u,v);
    int p = u ;


    int ans1 = 0 , ans2 = 0;
    while( lvl[u] > lvl[v] ) {
        int rise = log2(lvl[u] - lvl[v]);
        ans1 += (1<<rise);
        u = table[u][rise];
    }
    if( ans1 & 1 ) return 0;

    if( u == v ) {
        int dst1 = ans1/2;
        int node1 = get(p , dst1);
        int dst2 = dst1-1;
        int node2 = get(p , dst2 );
        return (sub[node1] - sub[node2]);
    }
    for(int logVal = log2(lvl[u]) ; logVal >=0 ; logVal-- ) {
        if( table[u][logVal] != -1 && table[u][logVal] != table[v][logVal]) {
            ans1 += (1<<(logVal)) ;
            ans2 += (1<<(logVal)) ;
            u = table[u][logVal];
            v = table[v][logVal];
        }
    }
//    cout<<u<<" "<<v<<" "<<sub[u]<<" "<<sub[v]<<endl;
    if( ans1 == ans2 ) return (n - sub[u] - sub[v]);
    int dst1 = (ans1+ans2+2)/2;
    int node1 = get(p , dst1);
    int dst2 = dst1-1;
    int node2 = get(p , dst2 );
    return (sub[node1] - sub[node2]);
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
    dfs(1,-1,0);
    build();
    cin>>m;
    while( m-- ) {
        int u , v;
        cin>>u>>v;
        cout<<solve(u,v)<<endl;
    }
    return 0;
}

/**
7
1 2
2 3
3 4
3 5
2 6
1 7
30
*/
