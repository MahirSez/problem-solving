#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e15;
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


int main() {

    int n;
    cin>>n;
    string s;
    cin>>s;
    int a = 0 , c = 0 , rq = 0 , lq = 0;

    for(auto x : s) {
        c += (x=='c');
        rq += (x=='?');
    }
    ll ans = 0;
    // cout<<a<<" "<<c<<" "<<lq<<" "<<rq<<'\n';

    for(auto x : s) {

        if(x == 'c') c--;
        if(x == '?') rq--;

        

        if(x == '?' || x == 'b') {

            ll tmp1 = 0 , tmp2 = 0;
            tmp1 = ( a * bigMod(3 , lq) )%MOD;
            if(lq) tmp2 = ( lq * bigMod(3 , lq-1) )%MOD;
            ll left = (tmp1 + tmp2) %MOD;

            

            tmp1 = 0 , tmp2 = 0;
            tmp1 = ( c * bigMod(3 , rq) )%MOD;
            if(rq) tmp2 = (rq * bigMod(3 , rq -1)) %MOD;
            ll right = (tmp1 + tmp2) %MOD;

            // cout<<left<<" "<<right<<'\n';

            ll tmp = (left * right) %MOD;
            ans += tmp;
            ans %= MOD;

            // cout<<a<<" "<<c<<" "<<lq<<" "<<rq<<" ->"<<tmp<<'\n';
        }

        if(x== 'a') a++;
        if(x == '?') lq++;
    }
    cout<<ans<<'\n';
    return 0;
}
