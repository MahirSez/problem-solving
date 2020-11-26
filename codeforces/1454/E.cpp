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
int par[N], no_c[N], deg[N], sub[N], vis[N];

void dfs(int node, int p) {

    vis[node] = 1;
    par[node] = p;
    sub[node] = 1;

    for(auto x : edg[node]) {
        if(vis[x] || no_c[x] == 0) continue;
        dfs(x, p);
        sub[node] += sub[x];
    }
}

int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        for(int i =1 ; i <=n ; i++ ) {
            edg[i].clear();
            par[i] = -1;
            no_c[i] = 0;
            deg[i] = 0;
            sub[i] = 0;
            vis[i] = 0;
        }

        for(int i =1; i <=n ; i++ ) {
            int u , v;
            cin>>u>>v;
            edg[u].push_back(v);
            edg[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        queue<int>q;
        for(int i =1 ; i <= n ; i++ ) {
            if(deg[i] == 1) q.push(i);
        }
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            no_c[top] = 1;

            for(auto x : edg[top]) {
                deg[x]--;
                if(deg[x] == 1) q.push(x);
            }
        }

        vector<int>circ;
        for(int i =1 ; i<=n ; i++ ) {
            if(no_c[i] == 0) circ.push_back(i);
        }

        for(auto x : circ) {
            dfs(x, x);
        }

        ll ans = 0;
        for(int i =1 ; i<=n ;i++ ) {
            ll chain_sz = sub[par[i]];
            ll baki = n - chain_sz;

            // cout<<i<<" "<<chain_sz<<" "<<baki

            ans += chain_sz-1 + baki*2;
        }
        assert(ans %2 == 0);
        ans/=2;
        cout<<ans<<'\n';
        
        
    }
    return 0;
}