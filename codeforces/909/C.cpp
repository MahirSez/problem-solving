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
using namespace std;
int  n , MOD  = 1e9 +7;
string tmp , str;
int dp[5005][5005];

int solve(int pos , int lvl) {

    if(pos == n ) return 1;
    if( dp[pos][lvl] != -1 ) return dp[pos][lvl];

    int num;
    if( pos && str[pos-1] == 'f') num = solve(pos+1 , lvl+1);

    else  {

        if( lvl == 0) num = solve(pos +1 , lvl);
        else num = solve(pos+1 , lvl ) + solve(pos, lvl-1);
    }
    num %= MOD;
    return dp[pos][lvl] = num;
}

int main()
{
    cin>>n;
    for(int  i =0 ; i < n ; i++) {
        cin>>tmp ;
        str += tmp;
    }
    memset(dp , -1, sizeof(dp) );

    cout<<solve(0,0)<<endl;
    return 0;

}
