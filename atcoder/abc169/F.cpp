#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 3e3 + 3;
const ll MOD = 998244353;

int n, s;

int ara[MAX], dp[MAX][MAX], ase[MAX];


int main()
{
    fastRead;
    cin>>n>>s;
    for(int i = 1; i <= n ; i++ ) {
        cin>>ara[i];
    }
    dp[0][0] = 1;
    
    for(int i = 1; i <=n ; i++ ) {
        
        for(int j = s ; j >= 0 ; j-- ) {
            
            dp[i][j] = (dp[i-1][j]*2)%MOD;
            if(j - ara[i] >=0) dp[i][j] = (dp[i][j] + dp[i-1][j-ara[i]])%MOD;
        }
    }
    cout<<dp[n][s]<<'\n';
    return 0;
}