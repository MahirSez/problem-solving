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
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int dp[MAX], mn;
int ara[200] , n , k;

int solve(int baki) {

    if( baki < mn ) {
        return 1;
    }
    int &ret = dp[baki];
    if( ret != -1 ) return ret;

    ret = 1;

    for(int i = 0 ; i < n ; i++ ) {
        if( ara[i] <= baki) {
            ret &= ( 1 ^ solve(baki - ara[i] ) );
        }
    }
    return ret;
}

int main()
{
    fastRead;
    cin>>n>>k;
    mn = INF;
    for(int i =0 ; i <n ; i++ ) {
        cin>>ara[i] , mn = min(mn , ara[i]);
    }
    memset(dp , -1 , sizeof dp);
    int ans = solve(k );
    if(ans == 0) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}


