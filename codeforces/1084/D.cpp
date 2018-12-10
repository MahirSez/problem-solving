#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
ll ara[MAX] , ans ,dp[MAX];
vector<pii>edg[MAX];

void dfs(int node, int par) {

    vector<ll>v;
    dp[node] = ara[node];
    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i].uu;
        ll wt = edg[node][i].vv;
        if( x==par) continue;
        dfs(x , node);
        if(dp[x] > wt) v.push_back(dp[x]- wt);
    }
    sort(v.rbegin() , v.rend());

    ans = max(ans , dp[node]);
    if( v.size() > 0 ) {
        dp[node] +=v[0];
        ans = max(ans , dp[node]);
    }
    if(v.size() > 1) {
        ans = max(ans , dp[node] + v[1]);
    }
}


int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i<=n ; i++ ) cin>>ara[i];
    for(int i =0 ; i < n -1 ; i++ ) {
        int u , v ;
        ll w;
        cin>>u>>v>>w;
        edg[u].push_back({v,w});
        edg[v].push_back({u,w});
    }
    dfs(1, 0);
    cout<<ans<<endl;
    return 0;
}
