#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    
        
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        
        ll n;
        cin>>n;
        ll sum =0;
        while(1) {
            
            if(n < 10) {
                sum += n;
                break;
            }
            
            ll tmp = n;
            ll ten = 1;
            while(tmp> 10) {
                
                ten *= 10;
                tmp/=10;
            }
            
            tmp *= ten;
            
            sum += tmp;
            n -= tmp;
            tmp/=10;
            n += tmp;
        }
        cout<<sum<<'\n';
    }
    return 0;
}