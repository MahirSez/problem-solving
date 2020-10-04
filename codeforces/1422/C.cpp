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
ll fact[N] , invfact[N];

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
    for(int i =1 ; i <  N ; i++) fact[i] = ( fact[i-1] * i )%MOD;
    
    invfact[N-1] = modInverse(fact[N-1]);
    for(int i = N-2 ; i >= 0 ; i--) invfact[i] = (invfact[i+1] * (i+1))%MOD;
}


int main()  {

    pre();
    fastio;
    string s;
    cin>>s;
    int n = s.size();

    vector<ll>pre(n+1);
    ll ten = 1;
    for(int i =1 ; i <=n ; i++ ) {
        pre[i] = pre[i-1] + 1LL*(ten * i);
        pre[i] %= MOD;
        ten *= 10;
        ten %= MOD;
        // cout<<pre[i]<<" ";
    }

    ll lt = 0 , rt = n;
    ll ans = 0;

    for(auto x : s) {
        rt--;
        ll tmp1 = pre[rt] + bigMod(10 , rt);
        tmp1 %= MOD;

        // cout<<tmp1<<'\n';
        ll tmp2 = 1LL*lt * (lt+1);
        tmp2 *= modInverse(2);
        tmp2 %= MOD;
        tmp2 *= bigMod(10 , rt);
        tmp2 %= MOD;

        // cout<<tmp1<<" "<<tmp2<<'\n';

        tmp1 += tmp2;
        tmp1  %= MOD;

        tmp1 *= (x-'0');
        tmp1 %=MOD;

        // cout<<tmp1<<'\n';
        ans += tmp1;
        ans %= MOD;

        lt++;
    }
    ll num = 0;
    // reverse(s.begin() , s.end());

    for(auto x : s) {
        num *=10;
        num %= MOD;
        num += (x-'0');
        num%= MOD;
    }

    // cout<<num<<'\n';

    
    ans -= num;
    ans %= MOD;
    ans = (ans + MOD) %MOD;
    cout<<ans<<'\n';
    return 0;
    
    
}