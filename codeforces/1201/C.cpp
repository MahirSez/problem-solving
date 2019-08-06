#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int const MAX = 1e6 + 6;
int n , k , ara[MAX];


bool ok(ll tgt) {


    ll tmp = 0;
    
    for(int i = n/2 ; i < n ; i++ ) {
        

        if( ara[i] < tgt ) tmp += tgt - ara[i];
    }
    
    return (tmp <= k);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>k;
    
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    
    sort(ara , ara + n);
    
    ll lo = 0 , hi = 1e12;
    
    ll ans = -1;
    while( lo <=hi ) {
        
        
        ll mid = (lo+hi)>>1;
        
        if(ok(mid)) {
            ans = mid;
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    
    cout<<ans<<endl;
    return 0;
    
}