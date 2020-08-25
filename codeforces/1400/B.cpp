#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;
int main() {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        ll p , f;
        cin>>p>>f;
        ll cnts , cntw;
        cin>>cnts>>cntw;
        ll s , w;
        cin>>s>>w;


        if(s > w) {
            swap(s,w);
            swap(cnts , cntw);
        }

        ll till = min(cnts , p / s);
        ll ans = 0;

        for(int i = 0; i <= till ; i++ ) {
            
            ll tot = i ;
            ll myrem = p - i * s;

            ll tmp = min(f/s , cnts - i);
            tot += tmp;

            ll parrem = f - tmp * s;


            ll tek1 = myrem / w;
            ll tek2 = min(parrem/w , cntw - tek1);

            tot += tek1 + tek2;

            ans = max(ans , tot);
        }
        cout<<ans<<'\n';
    }
    return 0;
}