#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    
    cin>>t;
    
    while(t-- ) {
        int k , n , a , b;
        cin>>k>>n>>a>>b;
        
        int tmp = k/b - (k%b ==0);
        
        if( tmp < n) {
            cout<<-1<<'\n';
            continue;
        }
        
        int lo = 0 , hi = n;
        int ans = -1;
        
        
        while(lo <= hi ) {
            ll mid = (lo+hi)/2;
            
            ll tmp = k - a*mid;
        
            ll cnt2 = (tmp / b) - (tmp%b == 0 );
//            cout<<cnt2<<" "<<mid<<" "<<tmp<<endl;
            
            if( tmp < 0 || mid + cnt2 < n) {
                    
                hi = mid-1;
            }
            else {
                lo = mid + 1;
                
                ans = mid;
            }
            
        }
        cout<<ans<<'\n';
    }
    return 0;
}