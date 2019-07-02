#include<bits/stdc++.h>
#define MAX 300005
#define INF 1e9
#define ll long long int 
using namespace std;


int const MOD = 1e9 + 7;

int n , T;
int typ[30] , val[30];

ll dp[(1<<15)][250][3];

ll solve(int mask , int taken ,int last) {
    
    if( taken  > T) return 0;
    if( taken == T) return 1;
    if( mask == (1<<n)-1 ) return 0;
    
    ll &ret = dp[mask][taken][last];
    if( ret != -1 ) return ret;
    
    ret = 0;
    
    for(int i = 0 ; i < n ; i++ ) {
        if( mask &(1<<i)) continue;
        if(typ[i] == last) continue;
        
        ret = ( ret + solve( (mask | (1<<i)) , taken + val[i] , typ[i]) ) %MOD;
    }
    return ret;
}


int main()
{
    cin>>n>>T;
    for(int i =0 ; i < n ; i++ ) cin>>val[i]>>typ[i];
    memset(dp , -1 , sizeof dp);
    cout<<solve( 0, 0 ,0)<<endl;
    return 0;
    
}