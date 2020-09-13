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


///a^b % MOD
ll bigMod(ll a , ll b) {

    ll p ;
    if( b == 0) return 1;
    p = ( bigMod(a , b/2) % MOD );
    p = ( p * p) % MOD;
    if( b & 1 ) p = ( p * a) % MOD;
    return p;
}
int main() {
    ll n; 
    cin>>n;
    ll a = bigMod(10 , n);
    ll b = bigMod(9 , n);
    ll c = bigMod(8 , n);
    ll ans = (a + c)%MOD;
    ans = (ans - b + MOD) %MOD;
    ans = (ans - b + MOD) %MOD;
    cout<<ans<<'\n';


    return 0;
}