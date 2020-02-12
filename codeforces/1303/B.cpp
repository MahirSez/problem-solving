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

ll n , g , b;

bool ok(ll day)  {
    
    
    ll times = (day) / (b+g) ;
    
    ll good = times *g ;
    
    good += min(day%(b+g) , g);
    
//    cout<<times<<" "<<good<<" "<<day<<'\n';
    
    return (good*2 >= n );
}
//1 10 1 10
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        
        cin>>n>>g>>b;
        
       ll lo = n , hi = INF , ans = -1;
       
        while(lo <=hi ) {

            ll mid = (lo+hi)/2;
            
            if(ok(mid)) {
                
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        cout<<ans<<'\n';
        
    }
    return 0;
    
}