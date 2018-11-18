#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e18
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll n , vis[MAX][2] , dp[MAX][2] , ara[MAX];

ll solve(int id , int taken) {

    if( id == n ) {
        if( taken ) return 0;
        return -INF;
    }
    ll &ret = dp[id][taken];
    if( vis[id][taken] ) return ret;

    vis[id][taken] = 1;

    ret= max( ara[id] + solve(id+1 , taken) , ara[id]*-1 + solve(id+1 , 1) );
    return ret;
}

int main()
{
    fastRead;
    cin>>n;
    ll sum = 0 , mx = -INF;
    bool found = false;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i] , sum+=ara[i]*-1 , mx = max(mx , ara[i]) ;
    if( n ==1 ) {
        cout<<ara[0]<<endl;
        return 0;
    }
    ll ans = solve(0,0);

    if( ans == sum) {
        cout<<ans + mx*2<<endl;
    }
    else cout<<ans<<endl;
    return 0;
}
