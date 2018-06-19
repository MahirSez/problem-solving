#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll x , k;
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
    cin>>x>>k;
    if( x ==0 ) {
        cout<<0<<endl;
        return 0;
    }
    ll ans = x %MOD;
    ans  = ( ans * bigMod(2,k+1LL) %MOD )  %MOD;
    ans = ( ans - bigMod(2, k) %MOD + MOD) % MOD;
    ans = (ans + 1LL )% MOD;
    cout<<ans<<endl;
    return 0;
}
