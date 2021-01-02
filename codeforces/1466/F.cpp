#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pip         pair<int,pii>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int n, m;

int par[N];

vector<pip> vec;


int boss(int x) {
    return par[x] = (par[x] == x) ? x : boss(par[x]);
}

set<int>baad;

vector<int>ids;

void mst() {

    for(int i = 1; i < N ; i++ ) par[i] = i;

    sort(vec.begin() , vec.end());

    for(auto x : vec) {
        int id = x.uu;
        int u = x.vv.uu;
        int v = x.vv.vv;
        
        int parU = boss(u);
        int parV = boss(v);

        if(parU == parV) {
            baad.insert(id);
            continue;
        }
        par[parU] = parV;
    }

}



ll pow2[N];

int main()  {
    fastio;

    pow2[0] = 1;
    for(int i =1 ; i < N ; i++ ) {
        pow2[i] = pow2[i-1] *2;
        pow2[i] %= MOD;
    }

    cin>>n>>m;


    for(int i =1 ; i <=n ; i++ ) {
        int tmp;
        cin>>tmp;
        if(tmp == 1) {
            int pos;
            cin>>pos;
            vec.push_back({i, {pos, m+1}});
        }
        else {
            int u, v;
            cin>>u>>v;
            vec.push_back({i, {u,v}});
        }
    }


    mst();


    vector<int>valid_ids;

    for(int i =1 ; i <= n ; i++ ) {
        if(baad.find(i) == baad.end()) valid_ids.push_back(i);
    }

    ll ans = pow2[valid_ids.size()];


    cout<<ans<<" "<<valid_ids.size()<<'\n';
    for(auto x : valid_ids) cout<<x<<" ";
    cout<<'\n';



    return 0;

}