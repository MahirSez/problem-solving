#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

const int MAX = 1e6 + 6;
ll fact[MAX] , invfact[MAX];

//a^b % MOD
ll bigMod(ll a , ll b) {

    ll p ;
    if( b == 0) return 1;
    p = ( bigMod(a , b/2) % MOD );
    p = ( p * p) % MOD;
    if( b & 1 ) p = ( p * a) % MOD;
    return p;
}


// (1/a) % MOD == (a ^ MOD-2 )%MOD
ll modInverse( ll x ) {
    return bigMod(x, MOD-2);
}


//nCr % MOD
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
int main() {

    pre();
    ll s;
    cin>>s;
    ll ans = 0;

    for(int i = 1 ; i<=s ; i++ ) {
        ll tgt = s - i* 3;
        if(tgt < 0) break;


        ll tmp = ncr(tgt + i - 1 , i-1);

        // cout<<i<<" "<<tgt<<" "<<tmp<<'\n';

        ans = (ans + tmp)%MOD;

    }

    cout<<ans<<'\n';

    return 0;
}