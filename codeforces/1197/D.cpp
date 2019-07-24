#include<bits/stdc++.h>
#define ll long long int
#define MAX 300005
using namespace std;

ll dp[MAX][20] , ara[MAX] ;
int n , m  , k;
ll ans;


ll solve(int id , int mm) {

    if( id == n ) return 0;

    ll &ret = dp[id][mm];
    if( ret != -1 ) return ret;


    ret = 0;
    int sub = 0;
    if( mm == 0) sub = k;

    ret = max( ret , ara[id] + solve(id+1 , (mm+1)%m ) - sub);
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    for(int i =0 ; i <n ; i++) cin>>ara[i];


    memset(dp , -1 ,  sizeof dp);

    for(int i = 0 ; i < n ; i++ ) {

        ans = max(ans  ,solve(i , 0));
    }



    cout<<ans<<endl;


    return 0;
}
