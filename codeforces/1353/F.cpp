#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

ll dp[200][200] , ara[200][200];

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n , m;
        cin>>n>>m;
        for(int i =1 ; i <=n ; i++ ) {
            for(int j = 1 ; j <= m ; j++ ) {
                cin>>ara[i][j];
            }
        }
        
        ll ans = INF;
        
        for(int i = 1 ; i <= n ; i++ ) {
            for(int j = 1 ; j <=m ; j++ ) {
                    
                    
                for(int ii = 1 ; ii <=n ;ii++ ) {
                    for(int jj =1 ; jj<=m ; jj++ ) {
                        dp[ii][jj] = INF;
                    }
                }
                
                ll dist = i + j - 2;
                ll fval = ara[i][j] - dist;
                dp[i][j] = 0;
                
                
                for(int ii = i ; ii >=1 ; ii--) {
                    for(int jj = j ; jj >=1 ; jj--) {
                        
                        if(ii == i && jj == j) continue;
                        
                        ll now = ii +jj -2 + fval;
                        if(ara[ii][jj] < now) continue;
                        
                        if(ii < i ) dp[ii][jj] = min(dp[ii][jj] , dp[ii+1][jj] + ara[ii][jj] - now);
                        if(jj < j ) dp[ii][jj] = min(dp[ii][jj] , dp[ii][jj+1] + ara[ii][jj] - now);
                    }
                }
                
                
                for(int ii = i ; ii <=n ; ii++ ) {
                    for(int jj = j ; jj <=m ; jj++ ) {
                        
                        if(ii == i && jj == j) continue;
                        
                        ll now = ii +jj -2 + fval;
                        if(ara[ii][jj] < now) continue;
                        
                        if(ii >i ) dp[ii][jj] = min(dp[ii][jj] , dp[ii-1][jj] + ara[ii][jj] - now);
                        if(jj > j ) dp[ii][jj] = min(dp[ii][jj] , dp[ii][jj-1] + ara[ii][jj] - now);
                    }
                }
                
                ans = min(ans , dp[1][1] + dp[n][m]);
                
            }
        }
        cout<<ans<<'\n';
        
    }
    return 0;
}