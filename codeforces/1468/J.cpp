#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

vector<tp>edg;

int par[N];

int n , m , k;

int boss(int x) {
    return (par[x] == x ? x : par[x] = boss(par[x]) );
}


ll mst() {
    for(int i = 1 ; i <= n ; i++ ) par[i] = i;
    ll ret  =0;

    for(auto x : edg) {
        int u , v , w;
        tie(w, u , v ) = x;
        int parU = boss(u);
        int parV = boss(v);
        if(parU == parV) continue;
        ret += max(0, w - k);
        par[parU] = parV;
    }
    return ret;
}

int main() {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        
        cin>>n>>m>>k;
        edg.clear();

        while(m-- ) {
            int u, v, w;
            cin>>u>>v>>w;
            edg.push_back({w, u, v});
        }
        sort(edg.begin() , edg.end());

        ll ret = mst();
        if(ret) {
            cout<<ret<<'\n';
            continue;
        }
        
        ret = INF;
        for(auto x : edg) {
            ret = min(ret, 1LL*abs(get<0>(x) - k));
        }
        cout<<ret<<'\n';
    }
    return 0;

}