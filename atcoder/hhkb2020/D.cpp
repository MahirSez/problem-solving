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


ll nc2(ll x) {
    ll ret =  (x * (x-1))/2;
    ret %= MOD;
    return ret;
}
int main() {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        ll n , a , b;
        cin>>n>>a>>b;
        if(a + b > n ) {
            cout<<0<<'\n';
            continue;
        }
        ll x = n -(a+b) + 2;
        ll ret = nc2(x);
        ret = (ret * (n-a+1)) % MOD;
        ret = (ret * (n-b+1)) % MOD;

        ll baad = ( nc2(x) * nc2(x) ) % MOD;
        ret -= baad;
        ret %= MOD;
        if(ret< 0) ret += MOD;
        ret *= 4;
        ret %= MOD;
        cout<<ret<<'\n';
    }
    return 0;
}