#include <bits/stdc++.h>
#define ll      	long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , k , a[200] , b[200] , dp[101][200005];

int solve(int id ,int taken) {
    if( id == n) {
        if( taken == 0 ) return 0;
        return -INF;
    }
    int &ret = dp[id][taken + 100000];
    if( ret != -1 ) return ret;
    ret =  solve(id+1 , taken) ;
    ret  = max( ret , solve(id+1 ,taken + (a[id]-b[id]*k) ) + a[id] );
    return ret;
}

int main()
{
    fastRead;
    cin>>n>>k;
    for(int i =0 ; i < n ; i++ ) cin>>a[i];
    for(int i =0 ; i < n ; i++ ) cin>>b[i];
    memset( dp , -1 , sizeof dp);
    int ans = solve(0 , 0);
    if( ans == 0 ) cout<<-1<<"\n";
    else cout<<ans<<"\n";
    return 0;
}
