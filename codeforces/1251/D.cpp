#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
  
  
const int MAX = 2e5 + 5;
ll sum , taken , l[MAX] , r[MAX];
int  n ;


bool ok(ll val) {

    ll tot = 0;
    vector<ll>vec;
    int sml = 0;
    
    for(int i =0 ; i < n ; i++ ) {
        
        if(val < l[i]) {
            tot += l[i];
        }
        else if(val > r[i]) {
            tot += l[i];
            sml++;
        }
        else {
            vec.push_back(l[i]);    
        }
    }
    if(sml > n/2) return false;
    sort(vec.begin() , vec.end());
    
    for(auto x : vec) {
        
        if(sml < n/2) {
            tot += x;
            sml++;
        }
        else tot += val;
    }
    return (tot <= sum);
}

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t-- ) {
        
        cin>>n>>sum;
        for(int i =0 ; i < n ; i++ ) cin>>l[i]>>r[i];
        
        ll lo = 0 , hi  = 1e9 , ans = -1;
        
        while(lo <=hi ) {
            
            ll mid = (lo+hi)/2;
            if(ok(mid)) {
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        cout<<ans<<'\n';
        
    }
    return 0;
}
