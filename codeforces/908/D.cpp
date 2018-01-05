#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS		1e-8
#define MAX		1000006
#define MOD		1000000007
using namespace std;

ll k , pa , pb ,ans;
ll dp[2000][2000];

ll bigMod(ll a , ll b) {

    ll p ;
    if( b == 0) return 1;
    p = ( bigMod(a , b/2) % MOD );
    p = ( p * p) % MOD;
    if( b & 1 ) p = ( p * a) % MOD;
    return p;
}

ll modInverse( ll x ) {
    return bigMod(x, MOD-2);
}

ll solve(ll a , ll ab) {

    if( ab >=k ) return ab;

    if( a >= k ) {

        ll tmp = ( (pb * (ab + a) ) % MOD + pa) % MOD;
        tmp = ( tmp * modInverse(pb) ) % MOD;
        return tmp;
    }

    ll &ret = dp[a][ab];
    if( ret != -1) return ret;

    ll  cnt1 = ( solve( a+1 , ab) * pa ) % MOD;
    cnt1 = (cnt1 * modInverse(pa + pb) ) % MOD;
    ll cnt2 = (solve (a ,ab +a ) * pb) % MOD;
    cnt2 = ( cnt2 * modInverse(pa + pb) ) % MOD;
    return ret = ( cnt1 + cnt2 ) % MOD;
}


int main()
{
    cin>>k>>pa>>pb;
    memset( dp , -1, sizeof(dp) ) ;
    cout<<solve(1 , 0)<<endl;
    return 0;
}
