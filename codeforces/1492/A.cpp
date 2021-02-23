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

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        ll p ;
        cin>>p;
        ll ans = INF;
        for(int i =0 ; i < 3 ; i++ ) {
            ll a;
            cin>>a;
            ll tmp = (p-1)/a + 1;
            tmp *= a;
            ans = min(ans, tmp - p);
        }
        cout<<ans<<'\n';
    }
    return 0;

}