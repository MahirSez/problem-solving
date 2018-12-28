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
#define MOD     	998244353
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
ll val[MAX];
string str , sub;
ll dp[MAX][6];

ll solve(int id1 , int id2) {

    if( id2 == 4) return INF;
    if( id1 == n ) return 0;
    ll &ret = dp[id1][id2];
    if(ret != -1) return ret;

    ret = INF;

    if( str[id1] == sub[id2] ) {

        ret = min(ret , solve(id1+1 , id2+1));
        ret = min(ret , solve(id1+1 , id2) + val[id1]);
    }
    else ret = min(ret , solve(id1+1 , id2));

    return ret;
}


int main()
{
    fastRead;
    cin>>n>>str;
    for(int i = 0 ; i < n ; i++) cin>>val[i];

    sub = "hard";
    memset(dp , -1 , sizeof dp);

    cout<<solve(0 , 0)<<endl;
    return 0;
}
