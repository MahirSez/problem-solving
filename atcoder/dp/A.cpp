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
ll ara[MAX] ,dp[MAX];

ll solve(int id) {

    if( id ==n-1 ) return 0;
    ll &ret = dp[id];
    if( ret != -1) return ret;

    ret = abs(ara[id+1] - ara[id]) + solve(id+1);

    if( id + 2 <n ) ret = min(ret , abs(ara[id+2] - ara[id]) + solve(id+2));
    return ret;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i = 0 ; i < n ; i++ ) cin>>ara[i];
    memset(dp , - 1, sizeof dp);
    cout<<solve(0)<<endl;
    return 0;
}
