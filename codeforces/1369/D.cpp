#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const ll MOD = 1e9 + 7;
const int MAX = 2e6+ 6;
ll dp[MAX], ans[MAX];

int main()
{
    fastRead;
    
    dp[1] = 1;
    for(int i = 2; i< MAX ; i++ ) {
        dp[i] = (dp[i-1] + 2LL*dp[i-2])%MOD;
    }
    
    for(int i = 1 ; i <=3 ; i ++) {
        ans[i] = dp[i];
        for(int j = i + 3 ; j < MAX ; j+=3) {
            ans[j] = (dp[j] + ans[j-3])%MOD;
        }
    }
//    cout<<'\n';
//    for(int i = 1; i <=10 ; i++ ) {
//        cout<<i<<" "<<ans[i]<<"\n";
//    }
////    return 0;    
    for(int i =1; i < MAX ; i++ ) {
        ans[i] = (ans[i] * 4)%MOD;
    }
    
    
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        n-=2;
        if(n <=0 ) cout<<0<<'\n';
        else cout<<ans[n]<<'\n';
    }
    return 0;
}