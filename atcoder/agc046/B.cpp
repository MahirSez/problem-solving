#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 3003;
const ll MOD = 998244353;

ll dp[MAX][MAX];

int main()
{
    fastRead;
    int r1 , c1, r2, c2;
    cin>>r1>>c1>>r2>>c2;
    
    dp[r1][c1] = 1;
    
    for(int i = r1 ; i <=r2 ; i++ ) {
        for(int j = c1 ; j <= c2 ; j++ ) {
            
            if(i > r1) dp[i][j] = (dp[i][j] + dp[i-1][j]*j ) % MOD;
            if(j > c1) dp[i][j] = (dp[i][j] + dp[i][j-1]*i ) % MOD;
            if(i > r1 && j > c1 ) dp[i][j] = (dp[i][j] - dp[i-1][j-1]*(i-1)*(j-1)) % MOD;
            if(dp[i][j] < 0 ) dp[i][j] += MOD;
        }
    }
    
    cout<<dp[r2][c2]<<'\n';
    return 0;
}