#include<bits/stdc++.h>
#define MOD  1000000007
#define ll long long int 
using namespace std;

ll dp1[2000][20] , dp2[2000][20];

int main()
{
    int n , m;
    cin>>n>>m;
    
    for(int i = 1 ; i <= n ; i++ ) dp1[i][1] = 1;
    
    for(int i =2 ; i <=m ; i++ ) {   //len
        
        for(int j = 1 ; j <= n ; j++ ) { //last
                
            for(int k = j ; k <=n ; k++ ) { //now
                
                dp1[k][i] = (dp1[j][i-1] + dp1[k][i])%MOD;
            }
            
        }
    }
    
    for(int i = 1 ; i<=n ; i++) dp2[i][m] = 1;
    
    for(int i = m-1 ; i>=1 ; i--) {
        
        for(int j = n ; j>=1 ; j-- ) {
            
            for(int k = j ; k >=1 ; k-- ) {
                
                dp2[k][i] = (dp2[j][i+1] + dp2[k][i]) %MOD;
            }
        }
    }
    ll ans = 0;
    
    for(int i = 1 ; i <=n ; i++  ) {
        
        for(int j = i ; j <=n; j++ ) {
            
            ll tmp = (dp1[i][m] * dp2[j][1]) % MOD;
            ans = (ans + tmp ) %MOD;
        }
    }
    cout<<ans<<'\n';
    return 0;
    
}