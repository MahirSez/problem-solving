#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m;
int cnt[MAX] , dp[MAX][5][5];

int solve(int id , int a , int b) {

    if( id == m-1) return ( (cnt[id]-a)/3 + (cnt[id+1]-b)/3 );
    if( id == m ) return (cnt[id]-a)/3;

    int &ret = dp[id][a][b];
    if( ret != -1 ) return ret;
    for(int i = 0 ; i <= 2 ; i++ ) {
        if(cnt[id]-a-i >= 0 && cnt[id+1] >= b+i  && cnt[id+2] >= i) {
            ret = max(ret , solve(id+1 , b+i , i) + (cnt[id]- a - i)/3 +i ); 
        }
    }
    return ret;

}
int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < n ; i++ ) {
        int tmp;
        cin>>tmp;
        cnt[tmp]++;
    }

    memset(dp , -1 , sizeof dp);
    cout<<solve(1 , 0  , 0 )<<endl;
    return 0;
}