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

const int N = 1e6 + 6;

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
    int n;
    cin>>n;
    vector<ll>vec(n);
    ll tot = 0;
    ll baad = 0;

    for(int i =0 ; i  < n ; i++ ) {
        cin>>vec[i];
        tot += vec[i];
        baad += vec[i]*vec[i];
        tot %= MOD;
        baad %= MOD;
    }

    tot *= tot;
    tot %= MOD;
    tot -= baad;
    tot %= MOD; 

    if(tot < 0 ) tot += MOD;

    ll ret = (tot * modInverse(2))%MOD;
    cout<<ret<<'\n';
    return 0;
    
    
}