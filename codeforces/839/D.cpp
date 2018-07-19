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
int n , ara[MAX] ;
ll cnt[MAX] , dp[MAX];

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
    cin>>n;
    for(int i = 0 ; i < n ; i++ ) cin>>ara[i];
    sort( ara , ara + n );
    for( int i =0 ; i< n ; i++ ) {
        for(int j = 2 ; j * j <= ara[i] ; j++ ) {
            if( ara[i]%j ==0  ) {
                cnt[j]++;
                if( j != ara[i]/j) cnt[ara[i]/j]++;
            }
        }
        cnt[ara[i]]++;
    }
    for(int i =2 ; i<= ara[n-1]; i++ ) {
//        cout<<cnt[i]<<endl;
        dp[i] = (cnt[i] * bigMod(2 , cnt[i]-1 )) % MOD;
    }
    ll ans = 0;
    for(int i = ara[n-1] ; i>= 2 ; i-- ) {

        if( cnt[i] == 0 ) continue;
        for(int j = i *2 ;  j<= ara[n-1] ; j+=i) {

            dp[i] = (dp[i] - dp[j] + MOD) % MOD;
        }
        ans = (ans + dp[i] * i) % MOD;
    }
    cout<<ans<<endl;
    return 0;

}
