#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS		1e-8
#define MAX		1000006
#define MOD		1000000007
using namespace std;
int n , d , tmp  ,mx= -1, ara[MAX];
int dp[50000][500];
int vis[50000][500];

int solve(int now , int len) {

    int tlen = d - len + 250;
    if( now > mx  ) {
        return 0;
    }
//    if( vis[now][tlen] ) return dp[now][tlen];
//    vis[now][tlen] = 1;
//    int ret;
    int &ret = dp[now][tlen];
    if( ret != -1 )
        return ret;

    int cnt1 =0 ,cnt2 =0, cnt3 =0 ;

    cnt1 = ara[now] + solve(now + len , len);

    cnt2 = ara[now ]  + solve(now + len +1 , len +1);

    if(len>1)
    cnt3 = ara[now ] + solve(now + len -1 , len -1);

    return  ret = max( cnt1  , max(cnt2 , cnt3) );
}

int main()
{
    scanf("%d %d",&n,&d);
    memset(dp , -1 , sizeof(dp));
    for( int i =0 ; i <n ; i++ ) {
        scanf("%d",&tmp);
        mx = max( tmp , mx);
        ara[tmp]++;
    }
    printf("%d\n",solve(d , d));
    return 0;
}
