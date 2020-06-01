#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e3 + 3;
const ll MOD = 1e9 + 7;


ll bigMod(ll a, ll b) {
    
    if(b == 0) return 1LL;
    ll ret = bigMod(a, b/2);
    ret = (ret * ret)%MOD;
    if( b & 1 ) ret = (ret * a) %MOD;
    return ret;
}
ll pw[MAX], fact[MAX], invfact[MAX];

void pre() {
    pw[0] = 1;
    for(int i =1 ; i <= 1000; i++ ) pw[i] = (pw[i-1]*2LL)%MOD;
    fact[0] = 1;
    for(int i = 1; i<= 1000 ; i++ ) fact[i] = (fact[i-1]*i)%MOD;
    invfact[1000] = bigMod(fact[1000], MOD-2);
    for(int i = 999; i>=0 ; i--) invfact[i] = (invfact[i+1] * (i+1) ) % MOD;
    
}

int main()
{
    pre();
    int n, m;
    cin>>n>>m;
    vector<int>vec(n+1);
    
    while(m--) {
        int tmp;
        cin>>tmp;
        vec[tmp] = 1;
    }
    
    int cnt =0;
    
    vector<int>rec;
    for(int i = 1; i <=n ; i++ ) {
        if(vec[i] ==1) {
            rec.push_back(cnt);
            cnt = 0;
        }
        else cnt++;
    }
    
    rec.push_back(cnt);
    
//    for(auto x : rec) cout<<x<<" ";
//    cout<<'\n';
    
    ll lob = 0;
    for(auto x: rec) lob += x;
    lob = fact[lob];
    ll hor = 1;
    for(auto x: rec) hor = (hor * invfact[x])%MOD;
    
//    cout<<lob<<" "<<hor<<'\n';
    
    ll ans = (lob * hor)%MOD;
    
    for(int i = 1; i < rec.size()-1 ; i++ ) {
        
        if(rec[i] == 0) continue;
        ans = (ans * pw[rec[i]-1])%MOD;
    }
    cout<<ans<<'\n';
    return 0;
}

