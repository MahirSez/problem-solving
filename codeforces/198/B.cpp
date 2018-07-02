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
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , k ;
int ara[2][MAX];
int  dp[2][MAX];
string str ;

int dfs(int id , int lvl , int tim) {
    if( tim > lvl ) return 0;
    if( lvl >= n ) return  1;
    if( ara[id][lvl] == -1) return 0;
    int &ret = dp[id][lvl];
    if( ret != -1 ) return  ret;
    ret = 0;
    ret |= dfs(id^1 , lvl+k , tim+1);
    ret |= dfs(id , lvl+1 , tim + 1 );
    ret |= dfs(id , lvl-1 , tim + 1 );
    return ret;
}

int main()
{
    fastRead;
    cin>>n>>k;
    cin>>str;
    for(int i =0 ; i < n ; i++ ) if( str[i] =='X') ara[0][i] = -1;
    cin>>str;
    for(int i =0 ; i < n ; i++ ) if( str[i] =='X') ara[1][i] = -1;
    memset( dp , -1 , sizeof dp);
    int ok = dfs(0 , 0 , 0);
    if( ok ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
