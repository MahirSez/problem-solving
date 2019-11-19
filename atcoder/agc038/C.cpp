#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         998244353
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;



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
ll fre[MAX] , sum[MAX] , sqsum[MAX] , ans[MAX];

int main()
{
    fastRead;
    
    int n ;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        int tmp;
        cin>>tmp;
        fre[tmp]++;
    }
    
    for(ll i =1 ; i <MAX ; i++ ) {
        
        for(ll j =i ; j < MAX ; j+=i) {
            
            sum[i] = (sum[i] + fre[j]*j)%MOD;
            sqsum[i] = (sqsum[i] + fre[j]*(j *j)%MOD )%MOD;
        }
    }
    
    for(int i =1 ; i <MAX ; i++ ) {
        
        ans[i] = ( (sum[i]*sum[i])%MOD + MOD-  sqsum[i] )%MOD;
        ans[i] = ( ans[i] *modInverse(2) )%MOD;
    }
    
    ll ret = 0;
    
    for(int i = MAX-1; i >=1 ; i--) {
        
        for(int j = i+i ; j< MAX ; j+=i) {
            
            ans[i] = (ans[i] + MOD - ans[j] )%MOD;
        }
        
        ret = (ret + ( ans[i] * modInverse(i) ) %MOD )%MOD;
    }
    
    cout<<ret<<'\n';
    return 0;
}