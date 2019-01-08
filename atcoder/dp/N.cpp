#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e18
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n;
ll ara[500] , sum[500] , dp[500][500];

ll solve(int frm , int to) {

    if( frm > to) return INF;

    if( frm == to ) return 0;
    ll &ret = dp[frm][to];
    if( ret != -1) return ret;

    ret = INF;

    for(int i = frm ; i <= to ; i++ ) {

        ret = min( ret , solve(frm , i ) + solve(i+1 , to)  + sum[to] - sum[frm-1] );
    }
    return ret;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i = 1 ; i<= n ; i++ ) cin>>ara[i];
    for(int i =1 ; i<= n ; i++ ) sum[i] = ara[i] + sum[i-1];
    memset(dp , -1 , sizeof dp);
    cout<<solve(1 , n)<<endl;
    return 0;
}
