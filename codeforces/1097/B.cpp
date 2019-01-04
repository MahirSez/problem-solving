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
int ara[20];
int dp[20][5000];

int solve(int id , int now) {

    if( id== n) return (now==0);

    int &ret = dp[id][now];
    if( ret != -1) return ret;
    ret = 0;

    int now1 = (now + ara[id])%360;
    int now2 = (now + 360-ara[id])%360;
    ret = solve(id+1 , now1) | solve(id+1 , now2);

    return ret;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++) cin>>ara[i];
    memset(dp , -1 , sizeof dp);
    int ok = solve(0,0);

    if( ok ==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
