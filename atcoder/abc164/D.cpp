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
const int MOD = 2019;


int cnt[30000];


ll bigMod(ll a , ll b) {

    ll p ;
    if( b == 0) return 1;
    p = ( bigMod(a , b/2) % MOD );
    p = ( p * p) % MOD;
    if( b & 1 ) p = ( p * a) % MOD;
    return p;
}

int main()
{
    fastRead;
    string str;
    cin>>str;
    cnt[0] = 1;
    int rem = 0;
    ll ans = 0;
    int zero = 0;
    for(int i = str.size() - 1 ; i >= 0 ; i-- ) {
        
        int id = str[i]-'0';
        
        rem = (bigMod(10 , zero++) * id + rem)%MOD;
        
        ans += cnt[rem];
        cnt[rem]++;
        
//        cout<<rem<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
    
    
}