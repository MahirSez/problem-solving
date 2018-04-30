#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int n , k;
ll dp[5000][5000];

ll solve(int now , int taken) {
//    cout<<now<<" "<<taken<<endl;
    if( taken == k ) return 1;
    ll &ret = dp[now][taken];
    if( ret != -1 ) return ret;
    ll ans =0;
    for(int i = 1 ; now*i<=n ; i++ ) {
        ans += solve(now*i , taken+1);
        ans %=MOD;
    }
    return ret = ans;
}

int main()
{
    cin>>n>>k;
    memset( dp , -1 , sizeof dp);
    cout<<solve(1 , 0)%MOD<<endl;
    return 0;
}
