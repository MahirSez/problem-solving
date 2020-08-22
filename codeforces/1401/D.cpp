#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

vector<int>edg[N];
ll sz[N];

void dfs(int node, int p) {
    sz[node] = 1;
    for(auto x : edg[node]) {
        if(x == p) continue;
        dfs(x, node);
        sz[node] += sz[x];
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
            sz[i] = 0;
        }
        for(int i = 0 ; i < n - 1 ; i++ ) {
            int u , v;
            cin>>u>>v;
            edg[u].push_back(v);
            edg[v].push_back(u);
        }

        dfs(1 , -1);
        int k;
        cin>>k;
        
        vector<ll>fact(k);
        for(auto &x : fact) cin>>x;
        
        sort(fact.rbegin() , fact.rend());

        if(k > n-1) {
            int till = k - n + 2;
            vector<ll>tmp;
            ll mul = 1;
            for(int i =0 ; i < till ; i++ ) {
                mul = (mul * fact[i])%MOD;
            }
            tmp.push_back(mul);
            for(int i =till ; i < k ; i++ ) tmp.push_back(fact[i]);
            fact = tmp;

            // cout<<till<<" "<<tmp.size()<<'\n';return 0;
            assert(fact.size() == n-1);
        }

        while(fact.size() < n-1) fact.push_back(1);

        vector<ll>ss;
        for(int i =2 ; i <= n ; i++ ) {
            ll tmp = (sz[i] * (n- sz[i]));
            ss.push_back(tmp);
        }
        sort(ss.rbegin() , ss.rend());
        for(auto &x : ss) x %= MOD;

        // cout<<fact.size()<<" "<<ss.size()<<'\n';

        // for(auto x : fact) cout<<x<<" ";
        // cout<<'\n';
        // for(auto x : ss) cout<<x<<" ";
        // cout<<'\n';
        ll ans = 0;
        for(int i =0 ; i < ss.size() ; i++ ) {
            ll tmp = (ss[i] * fact[i])%MOD;
            ans = (ans + tmp)%MOD;
        }
        cout<<ans<<'\n';
    }
    return 0;
}