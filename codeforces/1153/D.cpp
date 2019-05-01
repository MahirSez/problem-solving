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
int n ;
vector<int>edg[MAX];
int mark[MAX] , deg[MAX] ,dp[MAX];
int lf ;


void dfs(int node) {

    if( node != 1 && deg[node] == 0) {
        dp[node] = 1;
        return;
    }

    if( mark[node]) dp[node] = INF;

    for(auto x : edg[node]) {

		dfs(x);
        if( mark[node] ) {

            dp[node] = min(dp[node] , dp[x]);
        }
        else {
			dp[node] += dp[x];
        }
    }
}

int main()
{
    fastRead;
    cin>>n;
    for(int i = 1; i <= n ; i++ ) {
		cin>>mark[i];
    }

    for(int i =2 ; i<= n ; i++ ) {

        int tmp;
        cin>>tmp;
        deg[tmp]++;
        edg[tmp].push_back(i);
    }

    for(int i =2 ; i<= n ; i++ ) {
		if( deg[i] ==0 ) lf++;
    }
	dfs(1);
	cout<<lf - dp[1] + 1<<'\n';
	return 0;

}
