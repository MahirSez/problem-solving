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

int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        ll a, b;
        cin>>a>>b;
        ll flg = 0;
        if(b == 1) flg++, b++;
        ll ans = -1;


        for(ll i = b ; ; i++, flg++ ) {
            ll tmp = flg;

            ll aa = a;
            while(aa) {
                aa/= i;
                tmp++;
            }

            if(ans == -1 || ans >= tmp)  {
                ans = tmp;
            }
            else break;
        }
        assert(ans  != -1);
        
        cout<<ans<<'\n';
    }
    return 0;
}