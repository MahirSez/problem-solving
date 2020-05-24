#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        ll n , k;
        cin>>n>>k;
        ll till =sqrt(n) + 10;
        till =min(till , k);
        
        ll ans = n;
        
        for(int i = 1; i <=till ; i++ ) {
            
            if(n%i) continue;
            ll tmp1 = i;
            ll tmp2 = n/i;
            
            if(tmp1<=k) ans = min(ans , n/tmp1);
            if(tmp2<=k) ans = min(ans , n/tmp2);
        }
        cout<<ans<<'\n';
    }
    return 0;
}