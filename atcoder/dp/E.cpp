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
ll n , w;
ll wt[200];
int val[200] ;
ll dp[200][100005];

ll solve(int id , int tgt) {

    if( tgt < 0) return INF;
    if( id == n ) {
        if( tgt == 0 ) return  0;
        return INF;
    }
    ll &ret = dp[id][tgt];
    if( ret != -1 ) return ret;

    ret =solve(id+1 , tgt);

    ret = min( ret , wt[id] + solve(id+1 , tgt-val[id] ) );
    return ret;
}

int main()
{
    fastRead;
    cin>>n>>w;
    int tot = 0;
    for(int i =0 ; i < n ; i++ ) {
        cin>>wt[i]>>val[i];
        tot += val[i];
    }

    memset(dp , -1 , sizeof dp);
    int ans = 0;
    for(int i = 1 ; i <=  tot; i++ ) {

        ll wt = solve(0 , i);
        if( wt <= w) ans = i;
    }
    cout<<ans<<endl;
    return 0;
}
