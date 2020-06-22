#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int n;
    cin>>n;
    vector<ll>vec(n);
    vector< vector<ll> > dp( n+1, vector<ll>(n+1) );
    for(ll& x : vec) cin>>x;
    
    for(int i =0 ; i <n ; i++) {
        if(n&1) dp[1][i] = vec[i];
        else dp[1][i] = -vec[i];
    }
    
    for(int i = 2; i <= n ; i++ ) {
        for(int j =0 ; j + i - 1 < n ; j++ ) {
            if( ((n%2) ^ (i%2))  == 0 )
                dp[i][j] = max(dp[i-1][j] + vec[i + j - 1], dp[i-1][j+1] + vec[j]);
            else
                dp[i][j] = min(dp[i-1][j] - vec[i + j - 1], dp[i-1][j+1] - vec[j]);
            
        }
    }
    
    cout<<dp[n][0]<<'\n';
    return 0;
}