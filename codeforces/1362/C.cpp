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

ll pre[100];

int main()
{
    fastRead;
    
//    for(int i = 0 ; i <= 60 ; i++ ) {
//        pre[i] = 
//    }
    
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        
        ll ans = 0;
        while(n > 0) {
            
            int bit= 0;
            ll nn = n;
            while(nn) {
                nn/=2;
                bit++;
            }
            
//            cout<<n<<" "<<(1LL<<bit)-1<<" "<<(1LL<<(bit-1))<<'\n';
            ans += (1LL<<bit) - 1;
            n -= (1LL<<(bit-1));
        }
        cout<<ans<<'\n';
    }
    return 0;
}