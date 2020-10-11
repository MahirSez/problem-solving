#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e5 + 6;
int dp[N], mx[N] , t[N] , x[N] , y[N];

int main()  {
    fastio;
    int r , n;
    cin>>r>>n;
    x[0] = 1;
    y[0] = 1;
    for(int i =1 ; i <=n ; i++ ) cin>>t[i]>>x[i]>>y[i];

    for(int i =1 ; i <=n ; i++ ) dp[i] = -INF;

    for(int i =1 ; i <=n ; i++ ) {

        if(i - 2*r > 0) dp[i] = mx[i - 2*r - 1] + 1;
        for(int j = max( i - 2*r , 0) ;  j < i ; j++ ) {
            if( abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j] ) dp[i] = max(dp[i] , dp[j] + 1);
        }
        // cout<<i<<" "<<dp[i]<<'\n';
        mx[i] = max(dp[i] , mx[i-1]);
    }
    cout<<mx[n]<<'\n';
    return 0;
    
    
}