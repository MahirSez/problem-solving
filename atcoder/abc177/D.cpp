
#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

vector<int>edg[N];
int vis[N];

int dfs(int node)  {
    vis[node] = 1;
    int ret = 1;

    for(auto x : edg[node]) {
        if(vis[x] == 0 ) ret += dfs(x);
    }
    return ret;
}

int main()  {
    fastio;
    int n , m;
    cin>>n>>m;

    while(m--) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    int ans = 0;
    for(int i =1 ; i <= n ; i++ ) {
        if(vis[i]) continue;
        ans = max(ans , dfs(i));
    }
    cout<<ans<<'\n';
    
    
}