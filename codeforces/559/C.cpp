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
int h ,w ,n;
pii ara[5000];
ll dp[5000] , fact[MAX];


ll bigMod(ll a , ll b){
    ll p;
    if( b == 0 ) return 1;
    p = bigMod(a , b/2)%MOD;
    p = (p*p) % MOD;
    if( b & 1 ) p = (p * a) % MOD;
    return p;
}

ll modInverse(ll x) {
    return bigMod(x , MOD-2);
}

ll ncr(ll n , ll r) {
    if( n  < r || n < 0 || r < 0) return 0;
    ll lob = fact[n];
    ll hor = (fact[r] * fact[n-r]) % MOD;
    return ( lob * modInverse(hor) )% MOD;
}

ll ways(int frm , int to) {
    ll ans = ncr( (ara[to].uu - ara[frm].uu + ara[to].vv- ara[frm].vv) , (ara[to].vv- ara[frm].vv) );
//    cout<<ara[to].uu<<" "<<ara[to].vv<<" "<<ara[frm].uu<<" "<<ara[frm].vv<<" "<<ans<<endl;
    return ans;
}

ll solve(int id) {
    ll &ret = dp[id];
    if( ret != -1 ) return ret;
    ret = ways(0 , id);
    for( int i = 1 ; i < id ; i++ ) {
        ll tmp = (solve(i) * ways(i,id) )%MOD;
        ret = (ret - tmp + MOD) % MOD;
    }
    return (ret);
}

int main()
{
    fastRead;
    fact[0] = 1;
    for(int i =1 ; i< MAX; i++ ) {
        fact[i] = (i * fact[i-1]) % MOD;
    }
    cin>>h>>w>>n;
    for(int i =1 ; i<= n ; i++) {
        cin>>ara[i].uu>>ara[i].vv;
    }
    ara[0] = {1,1};
    ara[++n] = {h,w};
    sort( ara, ara + n + 1 );
    memset(dp , -1 , sizeof dp);
    cout<<solve(n)<<"\n";
    return 0;
}
