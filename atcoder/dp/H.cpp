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
int n , m  , ara[2000][2000];
string str;
ll dp[2000][2000];

ll solve(int x , int y) {

    if( ara[x][y] == -1) return 0;
    if( x == 0 && y ==0) return 1;

    ll &ret = dp[x][y];
    if( ret != - 1) return ret;

    ret = 0;

    if( x==0 ) ret  = solve(x , y-1);
    else if( y== 0 ) ret = solve(x-1 , y);
    else {

        ret = (solve(x-1 , y)%MOD + solve(x ,y-1) %MOD )%MOD;
    }
    return ret;
}

int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i  <n ; i++ ) {
        cin>>str;
        for(int j =0 ; j < m ; j++ ) {
            if( str[j] == '#') ara[i][j] = -1;
        }
    }
    memset(dp , -1 , sizeof dp);
    cout<<solve(n-1 , m-1)<<endl;
    return 0;
}
