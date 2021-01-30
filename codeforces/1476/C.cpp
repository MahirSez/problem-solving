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

const int N = 1e6 + 6;

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--)    {
        int n;
        cin>>n;
        vector<ll>a(n) , b(n) , c(n), dp(n);
        for(int i = 0; i < n ; i++) cin>>c[i];
        for(int i = 0; i < n ; i++) cin>>a[i];
        for(int i = 0; i < n ; i++) cin>>b[i];

        dp[0] = -INF;
        ll ans = 0;
        for(int i =1 ; i < n ; i++ ) {
            dp[i] = abs(a[i] - b[i]) + 2;
            if(a[i] != b[i]) {
                // cout<<"--"<<dp[i]<<" "<<dp[i-1]<<" "<<c[i-1]<<" "<<abs(a[i] - b[i])<<'\n';
                dp[i] = max(dp[i] , dp[i-1] + c[i-1] - 1  - abs(a[i] - b[i]) + 2);
            }

            // cout<<i<<" "<<dp[i]<<'\n';
            ans = max(ans, c[i] -1 + dp[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}