#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const ll MOD = 1e9 + 7;
const int MAX = 3e5 + 5;

int main()
{
    fastRead;
    int n , m;
    cin>>n>>m;
    vector<ll>sum(n+1);
    
    for(int i =1 ; i<=n ; i++) {
        sum[i] = (i+ sum[i-1])%MOD;
    }
    
//    for(auto x : sum )cout<<x<<" ";
//    cout<<'\n';
//    
    ll ans = 0;
    for(int i = m ; i <=n + 1 ; i++ ) {
        
        ll frm = sum[i-1];
        ll to = sum[n];
        if( n- i >= 0 ) to = (sum[n] - sum[n-i])%MOD;
        
//        cout<<i<<" "<<frm<<" "<<to<<'\n';
        
        ll tmp = (to -frm + MOD +1)%MOD;
        ans = (ans + tmp)%MOD;
    }
    
    cout<<ans<<'\n';
    
}