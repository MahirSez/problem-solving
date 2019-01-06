#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	2e9
#define EPS     	1e-8
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , ara[MAX][5] , dp[MAX][5];

int solve(int id , int prev) {

    if( id ==n ) return 0;

    int &ret = dp[id][prev];
    if( ret != -1)  return ret;

    ret = 0;
    for(int i =1 ; i <= 3; i++ ) {

        if( prev ==i ) continue;
//        cout<<id<<" "<<i<<endl;

        ret = max( ret , ara[id][i] + solve(id+1 , i) );
    }
    return ret;

}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        for(int j =1 ; j <= 3; j++ ) {
            cin>>ara[i][j];
        }
    }

    memset(dp , -1   ,sizeof dp);
    int ans = solve(0 , 0);
    cout<<ans<<endl;
    return 0;
}
