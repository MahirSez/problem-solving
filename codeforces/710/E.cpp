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
#define MAX     	10000007
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll n , x , y , dp[MAX];

ll solve(int num) {
    if( num == 1 ) return x;
    ll &ret = dp[num];
    if( ret != -1) return ret;
    if( num & 1) ret =  x + min(solve(num-1) , solve(num+1));
    else ret =  min(y , x*(num/2)) + solve(num/2) ;
    return ret;
}

int main()
{
    cin>>n>>x>>y;
    memset( dp , -1 , sizeof dp) ;
    cout<<solve(n)<<endl;
    return 0;
}
