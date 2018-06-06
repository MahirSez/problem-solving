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
int n ,dp[1004][20005][2], ara[1004], frm;

int solve(int now, int taken, int started) {
    if( now == n ) {
        return (taken==0);
    }
    int &ret = dp[now][taken+10004][started];
    if( ret != -1 )  return ret;
    ret = 0;
    if( taken == 0 && started) ret = 1;
    ret += solve(now+1 , taken + ara[now] , 1) ;
    ret %= MOD;
    ret += solve(now+1 , taken - ara[now] , 1) ;
    ret %= MOD;
    return ret;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i = 0 ; i < n ; i++)
        cin>>ara[i];
    memset(dp , -1, sizeof dp);
    int ans = 0;
    for(int i =0 ; i < n ;i++ ) {
        frm = i;
        ans += solve(i , 0, 0);
        //cout<<i<<" "<<solve(i,0,0)<<endl;
        ans %= MOD;
    }
    cout<<ans<<"\n";
    return 0;
}
