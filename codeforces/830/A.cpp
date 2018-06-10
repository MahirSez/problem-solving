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
#define MAX     	5000
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , k;
ll men[MAX] , key[MAX] , dest , dp[MAX][MAX];

ll solve(int id , int jd) {

    if( id== n ) return 0LL;
    if( jd == k ) return INF;
    ll &ret = dp[id][jd];
    if( ret != -1 ) return ret;
    ret = INF;
    ret = min( ret , max( solve(id+1 , jd+1) , abs(men[id]-key[jd]) + abs(key[jd] - dest) ) );
    ret = min( ret , solve(id , jd+1));
    return ret;
}

int main()
{
    fastRead;
    cin>>n>>k>>dest;
    for(int i =0 ; i < n ;i++ ) cin>>men[i];
    for(int i =0 ; i < k ;i++ ) cin>>key[i];
    sort( men , men+n);
    sort( key , key+ k);
    memset(dp , -1 , sizeof dp);
    cout<<solve(0,0)<<endl;
    return 0;
}
