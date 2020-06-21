#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 2e6 + 6;
const ll MOD = 1e9 + 7;

ll fact[MAX], invFact[MAX];

ll bigMod(ll a, ll b) {
    
    if(b == 0 ) return 1LL;
    ll ret = bigMod(a, b/2);
    ret = (ret *ret )%MOD;
    if(b&1) ret = (ret * a)%MOD;
    return ret;
}
ll invMod(ll x) {
    return bigMod(x, MOD-2);
}
void pre() {
    
    fact[0] =1;
    for(int i =1 ; i < MAX ; i++ ) {
        fact[i] = (fact[i-1] * i)%MOD;
    }
    
    invFact[MAX-1] = invMod(fact[MAX-1]);
    
    for(int i = MAX-2 ; i >=0 ; i--) {
        invFact[i] = (invFact[i+1] *(i+1))%MOD;
    }
//    for(int i =0 ; i < 5; i++ ) cout<<invFact[i]<<" ";
}

ll ncr(ll n, ll r) {
    
    
    ll lob = fact[n];
    
    
    ll hor = (invFact[r] * invFact[n-r])%MOD;
    
    return (lob * hor)%MOD;
}

int main()
{
    fastRead;
    pre();
    int k;
    string s;
    cin>>k>>s;
    int n = s.size();
    int tot = n + k;
    ll ans = bigMod(26, tot);
    
    
    for(int i =0 ; i < n ; i++ ) {
        
        ll tmp = (ncr(tot, i) * bigMod(25, tot-i))%MOD;
        ans = (ans - tmp)%MOD;
        ans = (ans + MOD)%MOD;
    }
    cout<<ans<<'\n';
    return 0;
}