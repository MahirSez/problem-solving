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


///a^b % MOD
ll bigMod(ll a , ll b) {

    ll p ;
    if( b == 0) return 1;
    p = ( bigMod(a , b/2) % MOD );
    p = ( p * p) % MOD;
    if( b & 1 ) p = ( p * a) % MOD;
    return p;
}
/// (1/x) % MOD
ll modInverse( ll x ) {
    return bigMod(x, MOD-2);
}


int main()  {
    fastio;  
    int n;
    cin>>n;
    ll p = 1;
    for(int i =1 ; i <= n ; i++) {
        p *= 2;
        p %= MOD;
    }

    vector<ll>dp(n+1), sum(n+1);
    dp[1] = 1;
    sum[1] = 1;

    for(int i = 2; i <= n ; i++ ) {

        if(i%2) dp[i] = 1 + sum[i-1];
        else dp[i] = sum[i-1];

        sum[i] = (dp[i] + sum[i-2])%MOD;
    }

    ll ans = (dp[n] * modInverse(p))%MOD;
    cout<<ans<<'\n';
    
    return 0;

}