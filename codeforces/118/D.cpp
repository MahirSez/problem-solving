#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS		1e-8
#define MAX		1000006
#define MOD     100000000
using namespace std;
ll n1, n2 , k1, k2 ,dp[101][101][11][11];

ll solve( ll a1, ll a2 , ll b1, ll b2) {

    if( a1==0  && a2== 0) return 1;

    if( dp[a1][a2][b1][b2] != -1) return dp[a1][a2][b1][b2];

    ll ans1 =0;
    if( a1 && b1) ans1 =solve( a1-1, a2 , b1 -1, k2)%MOD;
    if( a2 && b2) ans1 +=solve( a1, a2-1 , k1, b2-1 )%MOD;
    return  dp[a1][a2][b1][b2] = ( ans1  )%MOD;
}

int main()
{
    cin>>n1>>n2>>k1>>k2;
    memset( dp, -1 ,sizeof(dp ) ) ;
    cout<<solve(n1,n2,k1,k2);
    return 0;
}
