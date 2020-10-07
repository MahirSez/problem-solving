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

void dfs(int node) {
    vis[node] = 1;
    for(auto x : edg[node]) {
        if(vis[x] ==0) dfs(x);
    }
}

int main()  {
    fastio;
    int n , m;
    cin>>n>>m;
    while(m--) {
        int a , b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    int ans = 0;
    for(int i =1 ; i <=n ; i++ ) {
        if(vis[i]) continue;
        ans++;
        dfs(i);
    }
    cout<<ans-1<<'\n';
    return 0;
    
}