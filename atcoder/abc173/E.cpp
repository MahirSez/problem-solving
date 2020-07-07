#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
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
/// (1/x) % MOD
ll modInverse( ll x ) {
    return bigMod(x, MOD-2);
}

int main()
{
    fastRead;
    int n, k;
    cin>>n>>k;
    vector<pll>vec(n);
    for(int i =0 ; i < n ; i++ ) {
        cin>>vec[i].uu;
        if(vec[i].uu < 0 ) {
            vec[i].uu *= -1;
            vec[i].vv = -1;
        }
    }
    
    sort(vec.rbegin(), vec.rend());
    
    
    ll ans1 = 1;
    int par = 0;
    for(int i =0 ; i < k ; i++ ) {
        ans1 = (ans1 * vec[i].uu) % MOD;
        if(vec[i].vv) par ^=1;
    }
    if(par == 0 || ans1 ==  0) {
        cout<<ans1<<'\n';
        return 0;
    }
    
    ll p1 = 0 , p2 = 0;
    ll n1 = 0 , n2 = 0;
    
    for(int i =0 ; i < n ; i++) {
        
        if( i < k)  {
            if(vec[i].vv) n1 = 1;
            else p1 = 1;
        }
        else {
            if(vec[i].vv) n2 = 1;
            else p2 = 1;
        }
    }
    if(n1  + p1 + n2 + p2 == 4) {
        
        ll pos1 = 1, pos2= 1, neg1= 1, neg2 = 1;
        
        for(int i = 0 ; i < k ; i++) {
            if(vec[i].vv) neg1 = vec[i].uu;
            else pos1 = vec[i].uu;
        }
        for(int i = n-1 ; i >= k ; i-- ) {
                
            if(vec[i].vv) neg2 = vec[i].uu;
            else pos2 = vec[i].uu;            
        }
        
        if(pos1 * pos2 > neg1 * neg2) {
            ans1 = (ans1 * pos2)%MOD;
            ans1 = (ans1 * modInverse(neg1)) %MOD;
        }
        else  {
            ans1 = (ans1 * neg2)%MOD;
            ans1 = (ans1 * modInverse(pos1)) %MOD;            
        }
        
        cout<<ans1<<'\n';
        return 0;
    }
    
    if(n1 && p2) {
        
        ll neg1 = 1, pos2 = 1;
        
        for(int i = 0 ; i < k ; i++) {
            if(vec[i].vv) neg1 = vec[i].uu;
        }
        for(int i = n-1 ; i >= k ; i-- ) {
                
            if(vec[i].vv == 0) pos2 = vec[i].uu;            
        }
        
        ans1 = (ans1 * pos2)%MOD;
        ans1 = (ans1 * modInverse(neg1)) %MOD;
        cout<<ans1<<'\n';
        return 0;
    }
    
    if(n2 && p1) {
        
        ll neg2 = 1 , pos1 = 1;
        for(int i = 0 ; i < k ; i++) {
            if(vec[i].vv == 0) pos1 = vec[i].uu;
        }
        for(int i = n-1 ; i >= k ; i-- ) {
                
            if(vec[i].vv) neg2 = vec[i].uu;
        }
        ans1 = (ans1 * neg2)%MOD;
        ans1 = (ans1 * modInverse(pos1)) %MOD;            
        cout<<ans1<<'\n';
        return 0;
    }

    ll ans = 1;
    reverse(vec.begin(), vec.end());
    for(int i =0 ; i < k ; i++ ) {
        ans = (ans * vec[i].uu);
        if(vec[i].vv ) ans *= -1;
        ans %= MOD;
    }
    if(ans < MOD) ans += MOD;
    cout<<ans<<'\n';
    
    return 0;
}