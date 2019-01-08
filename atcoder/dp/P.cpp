#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n;
vector<int>edg[MAX];
ll dp[MAX][2];


int dfs(int node ,int par , int col ) {

    ll &ret = dp[node][col];
    if( ret!= -1) return ret;
    ret  = 1;

    for(auto x : edg[node]) {
        if(x == par) continue;
        if( col == 1) ret =(ret * dfs(x , node , 0) )%MOD ;
        else {
            ll tmp = ( dfs(x , node , 0)%MOD + dfs(x , node , 1)%MOD) % MOD ;
            ret = (ret * tmp)%MOD;
        }
    }
    return ret;
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
    memset(dp , -1 , sizeof dp);
    int ans = (dfs(1 , 0 , 0)  + dfs(1, 0 , 1)  ) %MOD;
    cout<<ans<<endl;


}
