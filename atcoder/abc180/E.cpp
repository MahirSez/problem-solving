#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int N = 18;


ll dp[N][(1<<N)];
ll x[N] , y[N] , z[N];
int n;

ll solve(int last , int mask)  {
    // cout<<mask<<'\n';
    if(mask == (1<<n)-1) {
        return abs(x[0] - x[last]) + abs(y[0] - y[last]) + max(0LL , z[0] - z[last]) ;
    }

    ll &ret = dp[last][mask];
    if(ret != -1) return ret;

    ret = INF;


    for(int i =0 ; i < n ; i++ ) {
        if(mask &(1<<i)) continue;
        // cout<<i<<" "<<mask<<" ";
        // cout<<abs(x[i] - x[last]) + abs(y[i] - y[last]) + max(0LL , z[i] - z[last]) <<'\n';
        ret = min(ret , abs(x[i] - x[last]) + abs(y[i] - y[last]) + max(0LL , z[i] - z[last]) + solve(i , mask | (1<<i) ) );
        // cout<<ret<<'\n';
    }
    return ret;
}

int main()  {
    fastio;

    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>x[i]>>y[i]>>z[i];

    memset(dp , -1 , sizeof dp);
    cout<<solve(0 , 1)<<'\n';
    return 0;


}