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
const ll MOD = 998244353 ;

ll fact[MAX] , invfact[MAX];


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

ll ncr(int n , int r) {
    if( n  < r || n < 0 || r < 0) return 0;
    ll up = fact[n];
    ll down = (invfact[r] * invfact[n-r])%MOD;
    return ( up * down )%MOD;
}

void pre() {
    
    fact[0] =1 ;
    for(int i =1 ; i <  MAX ; i++) fact[i] = ( fact[i-1] * i )%MOD;
    
    invfact[MAX-1] = modInverse(fact[MAX-1]);
    for(int i = MAX-2 ; i >= 0 ; i--) invfact[i] = (invfact[i+1] * (i+1))%MOD;
}

int main()
{
    fastRead;
    pre();
    int n , k;
    cin>>n>>k;
    
    if(n < k) {
        cout<<0<<'\n';
        return 0;
    }
    ll ans = 0;
    
    for(int i = 1; i <=n ; i++ ) {
        
        ll tmp = n / i;
        
        tmp = ncr(tmp-1 , k-1);
        
//        cout<<i<<" "<<n/i<<" "<<tmp<<'\n';
        
        ans = (ans + tmp)%MOD;
    }
    cout<<ans<<'\n';
    return 0;
}
