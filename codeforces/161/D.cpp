#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int n  , k , dp[100005][1000] ,ans;
vector<int>edg[MAX];

void dfs(int par ,int node) {

    dp[node][0] = 1;
    for(int j =0 ; j < edg[node].size() ; j++ ) {

        int x = edg[node][j];
        if( x == par) continue;
        dfs(node , x);
        for(int i = 0 ; i < k ; i++ ) {

            ans += dp[node][i] * dp[x][k-i-1];
        }
        for(int i = 0 ; i <= k ;i++ ) {
            dp[node][i+1] += dp[x][i];
        }
    }
}

int main()
{
    fastRead;
    cin>>n>>k;
    for(int i =0 ; i < n-1 ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    dfs(-1,1);
    cout<<ans<<endl;
    return 0;
}
