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
int n ;
ll ara[3003] ,dp[3003][3003][2];

ll solve(int l , int r , int turn) {

    if(l  > r) return 0;

    ll &ret= dp[l][r][turn];
    if( ret != -1) return ret;


    if( turn == 1 )
        ret = min( solve(l+ 1 , r , 0) - ara[l]  , solve(l , r-1 , 0) - ara[r]);
    else
        ret = max( solve(l+ 1 , r , 1) + ara[l]  , solve(l , r-1 , 1) + ara[r]);
    return ret;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    memset(dp , - 1, sizeof dp);
    cout<<solve(0 , n-1 , 0)<<endl;
    return 0;
}

