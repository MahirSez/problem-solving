#include<bits/stdc++.h>
#define ll long long int
#define MOD 998244353
using namespace std;

const int MAX = 2e5 + 6;
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

ll solve(int n , int k) {
    
    ll sum = 0;
    
    for(int i = 0 ; i <=k ; i++ ) {
        
        ll tmp = ( ncr(k,i) * bigMod(k-i , n) )%MOD;
        if(i&1) tmp *= -1;
        sum = (sum + tmp + MOD)%MOD;
    }
    sum = (sum * ncr( n , k))%MOD;
    
    return sum;
}

int main()
{
    pre();
    int n , k;
    cin>>n>>k;
    if(k >= n ) {
        cout<<0<<'\n';
        return 0;
    }
    ll ret = solve(n , n-k)  ;
    
    if(k > 0 ) ret = (ret*2)%MOD;
    
    cout<<ret<<'\n';
}

