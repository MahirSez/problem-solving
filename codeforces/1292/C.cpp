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

const int MAX = 3e3 + 6;
ll sub[MAX][MAX] , par[MAX][MAX] , dp[MAX][MAX];

int n;

vector<int>edg[MAX];

void dfs1(int node , int p , int rt) {  

    par[rt][node] = p;
    sub[rt][node] = 1;
    
    for(auto x : edg[node]) {
        
        if(x == p ) continue;
        
        dfs1(x , node , rt);
        
        sub[rt][node] += sub[rt][x];
    }
    
}

ll solve(int u , int v) {
    
    if(u ==v) return 0;
    
    ll &ret = dp[u][v];
    if( ret != -1) return ret;
    
    ret = sub[v][u] * sub[u][v];
    
    ret += max( solve(par[v][u] , v) , solve(u , par[u][v]) );
    return ret;

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
    
    for(int i =1 ; i <=n ; i++ ) {
        dfs1(i , -1 , i);
    }
    ll ans = 0;
    memset(dp , -1 , sizeof dp);
    
    for(int i =1 ; i <=n ; i++ ) {
        for(int j = i+1 ; j<=n ; j++ ) {
            ans = max( ans , solve(i , j) );
        }
    }
    cout<<ans<<'\n';
    return 0;
}