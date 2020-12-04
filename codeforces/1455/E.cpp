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

ll solve(vector<pll>&vec) {

    ll ret = INF;
    sort(vec.begin() , vec.end());

    for(int i =0 ; i < 4 ; i++ ) {
        for(int j =0 ; j < 4 ; j++ ) {
            for(int k =0 ;k < 4 ; k++) {

                ll x1 = vec[i].uu;
                ll x2 = vec[j].uu;
                ll y1 = vec[k].vv;

                ll dst = abs(x1 - x2);

                for(int ii = -1 ; ii <= 1 ; ii += 2) {

                    ll y2 = y1 + ii*dst;

                    do {
                        ll val = 0;
                        val += abs(vec[0].uu - x1) + abs(vec[0].vv - y1);
                        val += abs(vec[1].uu - x1) + abs(vec[1].vv - y2);
                        val += abs(vec[2].uu - x2) + abs(vec[2].vv - y1);
                        val += abs(vec[3].uu - x2) + abs(vec[3].vv - y2);

                        ret = min(ret, val);

                    } while(next_permutation(vec.begin() , vec.end()));
                    
                    sort(vec.begin() , vec.end());
                }
            }
        }
    }


    return ret;

}


int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        vector<pll>vec;
        for(int i =0 ; i < 4 ; i++  ) {
            ll x , y;
            cin>>x>>y;
            vec.push_back({x,y});
        }
        ll ret = solve(vec);
        for(auto &x : vec) swap(x.uu, x.vv);
        ret = min(ret , solve(vec));
        cout<<ret<<'\n';
    }
    return 0;
}