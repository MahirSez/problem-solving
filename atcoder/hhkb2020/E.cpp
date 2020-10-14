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

const int N = 2003;
int ara[N][N], ro[N][N] , col[N][N];


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
    int n , m;
    cin>>n>>m;
    int cnt= 0;

    for(int i = 1; i <=n ; i++ ) {
        string s;
        cin>>s;
        for(int j =1 ;j <= m ;j++ ) {
            if(s[j-1] == '#') ara[i][j] = -1;
            else cnt++;
        }
    }

    for(int i = 1 ; i <=n ; i++ ) {
        for(int j =1 ; j <=m  ; j++ ) {
            if(ara[i][j] == -1) ro[i][j] = 0;
            else ro[i][j] = ro[i][j-1] + 1;
        }

        for(int j = m-1 ; j >=1 ; j-- ) {
            if(ro[i][j] == 0) continue;
            else ro[i][j] = max(ro[i][j] , ro[i][j+1]);
        }
    }

    for(int j =1 ; j <= m ; j++ ) {
        for(int i =1 ; i <=n ; i++ ) {
            if(ara[i][j] == -1) col[i][j] = 0;
            else col[i][j] = col[i-1][j] + 1;
        }
        for(int i = n-1 ; i >=1 ; i-- ) {
            if(col[i][j] == 0) continue;
            else col[i][j] = max(col[i][j] , col[i+1][j] );
        }
    }

    ll ans = 0;

    for(int i= 1; i <=n ; i++ ) {
        for(int j =1 ; j <=m ; j++ ) {
            if(ara[i][j] == -1) continue;
            ll x = ro[i][j] + col[i][j] - 1;
            ll val1 = bigMod(2 , x) - 1;
            if(val1 < 0 ) val1 += MOD;
            ll val2 = bigMod(2 , cnt - x);

            // cout<<i<<" "<<j<<" "<<cnt<<" "<<val1<<" "<<val2<<'\n';
            val1 *= val2;
            ans += val1;
            ans %= MOD;
        }
    }
    cout<<ans<<'\n';
    return 0;

    
    
}