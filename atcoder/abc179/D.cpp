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
const ll MOD = 998244353;

const int N = 1e6 + 6;

int main()  {
    fastio;
    int n, k;
    cin>>n>>k;
    vector<pii>vec(k);
    vector<ll>dp(n+1);
    for(int i =0 ; i < k ; i++ ) cin>>vec[i].uu>>vec[i].vv;
    dp[1] = 1;
    for(int i = 2 ; i <= n ; i++ ) {
        for(auto x : vec) {

            int frm = max(0 , i - x.vv - 1);
            int to = max(0 , i - x.uu);
            dp[i] = (dp[i] + dp[to] - dp[frm])%MOD;
            if(dp[i] < 0) dp[i] += MOD;

        }
        dp[i] += dp[i-1];
        dp[i] %= MOD;
    
        // cout<<dp[i]<<"\n";
    }
    ll ans = (dp[n] - dp[n-1] + MOD )%MOD;
    cout<<ans<<'\n';

    return 0;


}