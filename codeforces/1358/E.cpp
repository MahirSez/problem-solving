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
/*
4
1000000000 999999999
-1000000000
*/
int main()
{
    fastRead;
    int n;
    cin>>n;
    vector<ll>vec(n+1) , sum(n+1) , to(n+1) , mn(n+1);
    for(int i =1 ; i <= (n+1)/2 ; i++) cin>>vec[i] ;
    ll x;
    cin>>x;
    for(int i =(n+1)/2 + 1 ; i <= n ; i++ ) vec[i] = x;
    
    if(x>=0) {
        ll sum = 0 ;
        for(auto x : vec) sum += x;
        if(sum > 0) cout<<n<<'\n';
        else cout<<-1<<'\n';
        return 0;
    }
    
    for(int i =1 ; i <= n; i++ ) {
        sum[i] = vec[i] + sum[i-1];
//        cout<<sum[i]<<" ";
    }
//    cout<<'\n';
        
    for(int i = 1 ; i <= (n+1)/2 ; i++) {
        
        int lo = i + n/2 , hi = n;
//        cout<<i<<" "<<lo<<" "<<hi<<' ';
        while(lo <=hi) {
            int mid = (lo+hi)/2;
            ll tmp = sum[mid] - sum[i-1];
            if(tmp > 0 ) {
                to[i] = mid - i + 1;
                lo = mid + 1;
            }
            else {
                hi = mid-1;
            }
        }
//        cout<<to[i]<<'\n';
    }
    mn[1] = to[1];
    
    for(int i =2 ; i <= (n+1)/2 ;i++ ) {
        mn[i] = min(mn[i-1] , to[i]);
    }
    for(int i = (n+1)/2  , k = n/2 + 1; i >=1 ; i-- , k++) {
        if(mn[i] >= k) {
            cout<<mn[i]<<'\n';
            return 0;
        }
    }
    cout<<-1<<'\n';
    return 0;
}