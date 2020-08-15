#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 3e3 + 3;
ll ara[N][N] , dp[N][N][5];

int main()  {
    fastio;
    int n, m , kk;
    cin>>n>>m>>kk;
    
    for(int i =0 ; i < kk ; i++ ) {
        int x , y, z ;
        cin>>x>>y>>z;
        ara[x][y] = z; 
    }

    for(int i =1 ; i <=n ; i++ ) {
        for(int j =1 ; j <=m ; j++ ) {
            
            dp[i][j][0] = max({ dp[i-1][j][0] , dp[i-1][j][1] , dp[i-1][j][2], dp[i-1][j][3] });
            dp[i][j][1] = max({ dp[i-1][j][0] , dp[i-1][j][1] , dp[i-1][j][2], dp[i-1][j][3] }) + ara[i][j];

            for(int k = 0 ; k <=3 ; k++ ) {
                dp[i][j][k] = max({dp[i][j][k] , dp[i][j-1][k]});
            }

            for(int k =1 ; k <=3 ; k++ ) {
                dp[i][j][k] = max({dp[i][j][k] , dp[i][j-1][k-1] + ara[i][j]});
            }

        }
    }
    ll ans = 0;
    for(int i =0 ; i <= 3 ; i++ ) ans = max(ans , dp[n][m][i]);
    cout<<ans<<'\n';
    return 0;
}