#include<bits/stdc++.h>
#define MAX 1000006
#define ll long long int
using namespace std;
int n , m ;
ll ara[4000][4000] ;
ll dp[4][2000][2000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    for(int i = 1 ; i  <= n ; i++) {

        for(int j =1 ; j <= m ; j++ ) {

            cin>>ara[i][j];
        }
    }
    
    for(int i = 1; i <= n ; i++ ) {
        for(int j =1 ; j <= m ; j++ ) {
            dp[0][i][j] = ara[i][j] + max(dp[0][i-1][j] , dp[0][i][j-1]);
        }
    }
    
    for(int i = n ; i>=1 ; i--) {
        for(int j = m ; j>=1 ; j-- ) {
            dp[1][i][j] = ara[i][j] + max(dp[1][i+1][j] , dp[1][i][j+1]);
        }
    }
    
    for(int i = 1 ; i <= n ; i++ ) {
        for(int j = m ; j>=1 ; j--) {
            dp[2][i][j] = ara[i][j] + max(dp[2][i-1][j] , dp[2][i][j+1]);
        }
    }
    
    for(int i = n ; i >=1 ; i-- ) {
        for(int j = 1 ; j <= m ; j++ ) {
            dp[3][i][j] = ara[i][j] + max(dp[3][i+1][j] , dp[3][i][j-1]);
        }
    }
    ll ans = 0;
    
    for(int i = 2 ; i <= n -1; i++ ) {
        for(int j = 2 ; j <= m-1 ; j++ ) {
            ans = max(ans , dp[0][i-1][j] + dp[1][i+1][j] + dp[2][i][j+1] + dp[3][i][j-1]);
            ans = max(ans , dp[0][i][j-1] + dp[1][i][j+1] + dp[2][i-1][j] + dp[3][i+1][j]);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
