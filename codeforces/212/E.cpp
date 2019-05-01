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
int n;
vector<int>edg[MAX] ;
int dp[MAX];

set<int>ans;

void dfs1(int node , int par) {

    dp[node] =1;
    vector<int>str;
    for(auto x: edg[node]) {

        if( x == par) continue;
        dfs1(x,node);
        str.push_back(dp[x]);
        dp[node] += dp[x];
    }

	if( node != 1) str.push_back(n - dp[node]);

    vector<bool> ret(n+1 , 0);

	ret[0] = 1;

    for(int i =0 ; i < str.size() ; i++ ) {

        int val = str[i];

        for(int j = n ; j >= 0 ; j--) {

            if( j>= val && ret[j-val] ) {
                ret[j] = 1;
            }
        }
    }

    for(int i = 1; i < n-1 ; i++ ) {

        if( ret[i] ) {
			ans.insert(i) ;
			ans.insert(n - i - 1);
        }
    }
}


int main()
{
	fastRead;
	cin>>n;
    for(int i =1 ; i < n ; i++ ) {

		int u , v;
		cin>>u>>v;
		edg[u].push_back(v);
		edg[v].push_back(u);
    }

    dfs1(1 , -1);
	cout<<ans.size()<<'\n';
    for(auto x : ans) {
		cout<<x<<" "<<n-x-1<<'\n';
    }
    return 0;
}
