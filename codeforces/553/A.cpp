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
int k , ara[10000] , sum;
ll dp[1001][1001],ans =1;

ll ncr(int i , int j) {

    if( j == 0 || i==j ) return 1;

    ll &ret = dp[i][j];

    if( ret !=-1 ) return ret;

    return ret = ( ncr(i-1 , j-1) + ncr(i-1 , j) ) % MOD;
}

int main()
{
    cin>>k;
    memset(dp, -1 ,sizeof(dp)) ;
    for( int  i= 0; i < k ; i++ ){
        int tmp;
        cin>>tmp;
        sum += tmp;
        ans = (ans * ncr(sum-1 , tmp-1) ) % MOD;
//        cout<<sum<<" "<<tmp<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
