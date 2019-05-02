#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
vector<pii>edg[MAX];
int n ;
ll ans , dp[MAX][4];

// 0
// 01
// 1
// 10

void dfs(int node , int par) {

    for(auto x: edg[node]) {
		if( x.uu== par) continue;

		int one = x.vv;
        int xx = x.uu;

		dfs(xx , node);

        if( one ) {
            dp[node][2] += dp[xx][2] +1 ;
            dp[node][3] += dp[xx][3] + dp[xx][0];
        }
        else {
			dp[node][0] += dp[xx][0] + 1;
            dp[node][1] += dp[xx][1] + dp[xx][2];
        }
    }

    ans += 2*dp[node][0] + 2*dp[node][2] + dp[node][1] + dp[node][3];

    for(auto x : edg[node]) {
        if( x.uu == par) continue;

        int one = x.vv;
        int xx = x.uu;

        if( one ) {

            ans += (dp[xx][0] + dp[xx][3] + dp[xx][2] + 1) * (dp[node][2] - (dp[xx][2] + 1)) ;
        }
        else {
			ans += (dp[xx][0] +1) * (dp[node][0] + dp[node][1] + dp[node][2] - (dp[xx][0] + dp[xx][1] + dp[xx][2] + 1) );
        }
    }

}




int main()
{
	fastRead;
	cin>>n;
	for(int i = 0 ; i < n-1 ; i++ ) {
		int u , v , c;
		cin>>u>>v>>c;
		edg[u].push_back({v,c});
		edg[v].push_back({u,c});
	}
    dfs(1 ,0 );
    cout<<ans<<endl;
    return 0;
}
