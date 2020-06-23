#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll dp[200][MAX];

int main()
{
    fastRead;
    int n, k;
    cin>>n>>k;
    vector<int>vec(n+1);
    ll tot = 0;
    for(int i =1 ; i <=n ; i++) cin>>vec[i], tot += vec[i];
    
    dp[0][0] = 1;
    for(int i = 1; i <=n ; i++ ) {
        
        vector<ll>pref(k+1);
        pref[0] = dp[i-1][0];
        
        for(int j =1 ; j <=k ; j++ ) pref[j] = (dp[i-1][j] + pref[j-1]) % MOD;
//        for(ll x : pref) cout<<x<<" ";
//        cout<<'\n';
        
        for(int j = 0 ; j <= k ; j++ ) {
            
            int frm = max(0, j - vec[i]), to = j;
            
            ll sum = pref[to];
            if(frm) sum = (sum - pref[frm-1] + MOD )%MOD;
//            cout<<j<<" "<<sum<<'\n';
            
            dp[i][j] = (dp[i][j] + sum + MOD) % MOD;
        }
    }
    cout<<dp[n][k]<<'\n';
    return 0;
}