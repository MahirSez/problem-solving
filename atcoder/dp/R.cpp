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
const ll MOD = 1e9 + 7;

ll n, kk;
ll dp1[70][70][70], dp2[70][70];

ll dfs(int now, int id) {
    
    if(id == -1) return 1;
    if( (kk & (1LL<<id)) == 0 ) return dfs(now, id-1);
    
    ll &ret = dp2[now][id];
    if(ret != -1)  return ret;
    
    ret = 0;
    for(int i = 1; i <=n ; i++ ) {
        ll tmp = (dp1[now][i][id] * dfs(i, id-1) )%MOD;
        ret = (ret + tmp)%MOD;
    }
    return ret;
}

int main()
{
    fastRead;
    cin>>n>>kk;
    for(int i =1 ; i <=n ; i++ ) {
        for(int j =1 ; j <=n ; j++) {
            cin>>dp1[i][j][0];
        }
    }
    
    for(int i = 1 ; i <= 63; i++  ) {
        
        for(int j = 1; j <=n ; j++ ) {
            for(int k = 1; k <= n; k++) {
                for(int l = 1 ; l <=n ; l++ ) {
                    ll tmp = (dp1[j][l][i-1] * dp1[l][k][i-1]);
                    dp1[j][k][i] = (dp1[j][k][i] + tmp) % MOD;
                }
            }
        }
    }
    
//    for(int i = 1; i <=n ; i++ ) dp2[i][0] = 1;
    
//    for(int i =1 ; i <=n ; i++ ) {
//        for(int j= 1 ; j <=n ; j++ ) {
//            dp2[i][0] += dp1[i][j][0];
//        }
////        cout<<1<<" "<<i<<" -- "<<dp2[i][0]<<'\n';
//        if(dp2[i][0] && kk%2 ==0) dp2[i][0] = 1;
//    }
//    
//    for(int i = 0; i <= 63; i++ ) {
//        for(int j =1 ; j <=n ; j++ ) {
//            
//            if( i  && (kk & (1LL<<i ) ) == 0 ) {
//                dp2[j][i] = dp2[j][i-1];
//                continue;
//            }
//            for(int k = 1 ; k <=n ; k++ ) {
//                ll tmp  = dp1[j][k][i] ;
//                if(i) tmp = (tmp * dp2[k][i-1])%MOD;
//                dp2[j][i] = (dp2[j][i] + tmp) % MOD;
//            }
//            cout<<(1LL<<i)<<" "<<j<<" -- "<<dp2[j][i]<<'\n';
//        }
//    }
//
//    
    
//    ll ans = 0;
//    for(int i =1; i <=n ; i++ ) {
//        ans = (ans + dp2[i][63] )%MOD;
//    }

    memset(dp2, -1 , sizeof dp2);
    ll ans = 0;
    for(int i =1; i <=n ; i++ ) {
        ans = (ans + dfs(i, 63) )%MOD;
    }
    cout<<ans<<'\n';
    return 0;
    
}