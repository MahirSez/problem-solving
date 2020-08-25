#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;

    int n , k;
    cin>>n>>k;
    vector<ll>dp(n+1);
    
    string s;
    cin>>s;
    s= '*' + s;

    set<pll>st;

    for(int i =1 ; i <=n ; i++ ) {

        while(st.size() &&  i - (*st.begin()).vv > k ) st.erase(st.begin());

        dp[i] = dp[i-1] + i;

        if(st.size()) dp[i] = min(dp[i] , (*st.begin()).uu);

        if(s[i] == '1') {
            dp[i] = min(dp[i] ,dp[max(0 , i - k -1)] + i );
            ll val = dp[max(0 , i - k -1)] + i;
            if(st.size()) val = min(val ,  (*st.begin()).uu + i);
            st.insert({val, i});
        }

        // cout<<i<<" "<<dp[i]<<'\n';
        
    }

    cout<<dp[n]<<'\n';
    return 0;
    
}