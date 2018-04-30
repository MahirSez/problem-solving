#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int t , a , b;
ll dp[MAX] ,  sum[MAX],  k;

ll solve(int id) {

    if( id  == 0 ) return 1LL;
    ll &ret = dp[id];
    if( ret != -1 ) return ret;
    ret = 0;
    if( id > 0 ) ret = solve(id-1);
    ret %=MOD;
    if( id - k >= 0 ) ret += solve(id-k) ;
    return ret %= MOD;
}

int main()
{
    scanf("%d %lld",&t , &k);
    memset( dp , -1 , sizeof dp);

    for(int i = 1 ; i <=100000 ; i++ ) {
        sum[i] = (sum[i-1]  + solve(i)) % MOD;
    }
    while( t-- ) {

        scanf("%d %d",&a ,&b);
        printf("%d\n" , (sum[b] - sum[a-1] + MOD) % MOD);
    }
    return 0;
}
