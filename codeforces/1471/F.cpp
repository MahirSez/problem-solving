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

int n, m;
vector<int>edg[N];
int vis[N], col[N];
int tot = 0;

vector<int>ans;

void dfs(int node) {

    vis[node] = 1;
    tot++;

    if(col[node] == 0) {
        col[node] = 1;
        ans.push_back(node);

        for(auto x : edg[node]) {
            assert(col[x] != 1);

            col[x] = 2;
        }
    }

    for(auto x : edg[node]) {
        if(vis[x] == 0) dfs(x);
    }
}

int main()  {
    fastio;
    int t;

    cin>>t;
    while(t--) {
        
        cin>>n>>m;
        tot = 0;
        ans.clear();
        for(int i =1 ;i <=n ; i++ ) {
            edg[i].clear();
            vis[i] = 0;
            col[i] = 0;
        }

        while(m--) {
            int u, v;
            cin>>u>>v;
            edg[u].push_back(v);
            edg[v].push_back(u);
        }

        dfs(1);
        if(tot < n ) {
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
        cout<<ans.size()<<'\n';
        for(auto x : ans) cout<<x<<" ";
        cout<<'\n';

    }
    return 0;
}