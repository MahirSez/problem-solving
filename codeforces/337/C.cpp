#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 9;

const int N = 2e5 + 6;



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
    fastio;
    ll n , m , k;
    cin>>n>>m>>k;

    ll tmp = (n / k ) * (k-1) + n%k;

    if(tmp >= m) {
        cout<<m<<'\n';
        return 0;
    }

    ll rem = m - tmp;

    ll ans = bigMod(2 , rem + 1) - 2;
    if(ans < 0 ) ans += MOD;
    ans = (ans * k)%MOD;

    ans += m - (rem*k);
    ans %= MOD;
    cout<<ans<<'\n';

    return 0;







}