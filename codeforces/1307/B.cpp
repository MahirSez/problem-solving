#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        ll n , x;
        cin>>n>>x;
        
        
        ll ans = INF;
        for(int i =0 ; i < n ; i++ ) {
            ll tmp;
            cin>>tmp;
            if(tmp > x) ans = min(ans ,2LL);
            else ans = min(ans , (x-1)/tmp + 1LL );
        }
        
        cout<<ans<<'\n';
    }
    return 0;
    
}