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
int t , n , m , adj[500][500] ,deg[500] , vis[500];
vector<pii>ans;

void dfs(int node) {

    vis[node] = 1;
    for(int i =0 ; i <= n ;i++ ) {
        if( adj[i][node] ==0 ) continue;
        adj[i][node] = 0;
        adj[node][i] = 0;
        if( node && i) ans.push_back({node , i});
        dfs(i);
    }
}

int main()
{
    fastRead;
    cin>>t;
    while( t-- ) {
        memset(adj , 0 , sizeof adj);
        memset(deg , 0 , sizeof deg);
        memset( vis, 0 , sizeof vis);
        ans.clear();
        cin>>n>>m;
        for(int i =0 ; i < m ; i++ ) {
            int u , v;
            cin>>u>>v;
            adj[u][v] = 1;
            adj[v][u] = 1;
            deg[u]++;
            deg[v]++;
        }

        int cnt = 0;
        for(int i =1; i<=n ; i++ ) {

            if( deg[i]&1 ) {
                adj[0][i] = 1;
                adj[i][0] = 1;
            }
            else cnt++;
        }

        for(int i = 0; i <= n ; i++ ) {
            if( vis[i] ) continue;
            dfs(i);
        }
        cout<<cnt<<'\n';
        for(int i =0 ; i < ans.size() ; i++ ) {
            cout<<ans[i].uu<<" "<<ans[i].vv<<'\n';
        }
    }
    return 0;
}
