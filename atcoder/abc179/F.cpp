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
const ll MOD = 998244353;

const int N = 2e5 + 6;
int n , q;

ll ans;

void update(int flg, vector<pii>&vec ) {
    vector<int> rec(n+1, n);
    int last = n;

    for(auto xx : vec) {
        int typ , x;
        tie(typ , x) = xx;
        if(typ == flg) {
            rec[last] = min(rec[last] , x);
        }
        else {

            if(x > last) ans -= (rec[x] - 2);
            else {

                for(int i = last - 1 ; i >= x ; i-- ) rec[i] = rec[last];
                last = x;
                ans -= (rec[x] - 2);
            }
        }
    }

}

int main()  {
    fastio;
    
    cin>>n>>q;
    vector<pii>vec(q) ;
    
    for(int i =0 ; i < q; i++ ) cin>>vec[i].uu>>vec[i].vv;

    ans = 1LL*(n-2)*(n-2);

    update(2, vec);
    update(1 , vec);
    
    cout<<ans<<'\n';
    
    return 0;




}