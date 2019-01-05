#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll n , ans , dp[20000][60] , power[60] , inv[100];
int k;

ll bigMod(ll a ,ll b) {
    if( b==0) return 1;
    ll p = (bigMod(a , b/2) %MOD);
    p = (p*p)%MOD;
    if( b & 1) p = (p*a)%MOD;
    return p;
}

ll modInverse( ll x ) {
    return bigMod(x, MOD-2);
}


ll solve(ll prime , int fre) {

    power[0] = 1;
    for(int i =1 ; i<= fre ; i++ ) {
        power[i] = (power[i-1] * prime)%MOD;
    }

    for(int i = 0 ; i <=fre ; i++ ) dp[0][i] = power[i];

    for(int i =1 ; i<= k ; i++ ) {
        ll sum = 0;
        for(int j =0 ; j <=fre ; j++ ) {
            sum = (sum + dp[i-1][j] ) %MOD;
            dp[i][j] = (sum * inv[j+1] )%MOD;
        }
    }

    return dp[k][fre];
}


int main()
{
    cin>>n>>k;
    ans = 1;
    for(int i =1 ; i<= 60 ; i++ ) inv[i] = modInverse(i);
    for(ll i = 2; i * i <=n; i++) {

        int cnt = 0;
        if( n%i) continue;
        while( n%i == 0) {
            n/=i;
            cnt++;
        }

        ll tmp = solve(i , cnt);
        ans = (tmp * ans)%MOD;
    }
    if( n > 1) {
        ans = (ans * solve(n , 1) )%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
