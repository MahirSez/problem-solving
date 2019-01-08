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
int n;
ll dp[(1<<21) + 100];
int ara[30][30];


ll solve(int mask) {

    if( mask == (1<<n) -1 ) return 1;

    ll &ret = dp[mask];
    if( ret != -1) return ret;

    ret = 0;

    int id = __builtin_popcount(mask);

    for(int i = 0 ; i < n ; i++ ) {
        if( ara[id][i] && (mask & (1<<i) ) ==0 ) {
            ret = ( ret + solve(mask | (1<<i) ) %MOD ) %MOD;
        }
    }
    return ret;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        for(int j = 0 ; j < n ; j++ ) {
            cin>>ara[i][j];
        }
    }

    memset(dp , -1 , sizeof dp);
    cout<<solve(0)<<endl;
    return 0;
}
