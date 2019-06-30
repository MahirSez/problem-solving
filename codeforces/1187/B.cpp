#include<bits/stdc++.h>
#define MAX 200005
using namespace std;
int t , n , sum[30][MAX] , ara[30];
string str ;

bool ok(int id) {
    
    for(int i = 0 ; i < 30 ; i++ ) {
        
        if(sum[i][id] < ara[i]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin>>str;
    for(int i = 1 ; i <= n ; i++ ) {
        
        sum[(str[i-1]-'a')][i] = 1;
    }
    
    for(int i = 1 ; i<= n ; i++) {
        for(int j =0 ; j < 30 ; j++) sum[j][i] += sum[j][i-1];
    }
    cin>>t;
    while( t-- ) {
        cin>>str;
        memset(ara , 0 , sizeof ara);
        
        for(int i =0 ; i < str.size(); i++ ) {
            ara[(str[i]-'a')]++;
        }
        
        int lo = 0 , hi = n;
        int ans = -1;
        
        while( lo <= hi ) {
            
            int mid = (lo+hi)>>1;
            if(ok(mid)) {
                ans = mid;
                hi=mid-1;
            }
            else lo = mid+1;
        }
        cout<<ans<<'\n';
        
    }
    return 0;
    
}