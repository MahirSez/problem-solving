#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	998244353
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int a , b , c;
ll ab , bc , ac ,fact[6000];

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

ll ncr(ll n , ll r) {
    if( n  < r || n < 0 || r < 0) return 0;
    ll lob = fact[n];
    ll hor = (fact[r] * fact[n-r]) % MOD;
    return ( lob * modInverse(hor) )% MOD;
}


int main()
{
    cin>>a>>b>>c;
    fact[0] = 1;
    for(int i =1 ; i < 6000 ; i++) {
        fact[i] =( i * fact[i-1]) %MOD;
    }
    for(int i = 0; i <= min(a,b) ; i++ ) {
        ab = ( ab + ( ( (ncr(a,i) * ncr(b,i) ) % MOD) * fact[i] )% MOD ) %MOD;
    }
    for(int i = 0; i <= min(a,c) ; i++ ) {
        ac = ( ac + ( ( (ncr(a,i) * ncr(c,i) ) % MOD) * fact[i] )% MOD ) %MOD;
    }
    for(int i = 0; i <= min(b,c) ; i++ ) {
        bc = ( bc + ( ( (ncr(c,i) * ncr(b,i) ) % MOD) * fact[i] )% MOD ) %MOD;
    }
    cout<<( ( (ab*bc)%MOD ) * ac )%MOD<<endl;
    return 0;
}

