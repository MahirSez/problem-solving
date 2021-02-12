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
        ll a,b;
        cin>>a>>b;
        ll ans = 0;

        for(int i = 1 ; ; i++ ) {
            ll tmp = min(b-i, a/i - i - 1);

            // cout<<i<<" "<<tmp<<'\n';
            if(tmp < 0) break;
            ans += tmp;
            
        }
        cout<<ans<<'\n';
    }
    return 0;
}