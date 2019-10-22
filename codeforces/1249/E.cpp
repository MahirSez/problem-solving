#include<bits/stdc++.h>
#define ll  long long int
using namespace std;
const int MAX = 2E5 + 5;
ll a[MAX] , dp[MAX][2] , b[MAX] , ans[MAX];
ll c;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n>>c;
    for(int i =1 ; i <n ; i++ ) cin>>a[i];
    for(int i =1 ; i <n ; i++ ) cin>>b[i];
    
    
    dp[0][1] = c;
    for(int i =1 ; i < n ; i++ ) {
        
        dp[i][0] = min( dp[i-1][0] + a[i] ,dp[i-1][1] + a[i]) ;
        dp[i][1] = min(dp[i-1][0] + b[i] + c , dp[i-1][1] + b[i]);
        
        
//        cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<'\n';
        ans[i] = min(dp[i][0] , dp[i][1]);
    }
    
    for(int i =0 ; i < n ; i++ ) cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
}