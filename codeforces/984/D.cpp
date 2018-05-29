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
int n , q , ara[6000] , dp[6000][6000] , ans[6000][6000];

int solve(int l , int r) {
    if(l == r) return ara[l];
    int &ret = dp[l][r];
    if( ret != -1 ) return ret;
    ret = solve(l , r-1 ) ^ solve(l+1 ,r);
    return ret;
}


int getMax(int l , int r) {
    if( l == r) return ara[l];
    int &ret = ans[l][r];
    if( ret != -1) return ret;
    ret = max( solve(l ,r) , max( getMax(l+1 , r) , getMax(l , r-1) ) );
    return ret;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i <= n ; i++ ) {
        cin>>ara[i];
    }
    memset( dp , -1 , sizeof dp);
    memset( ans , -1 , sizeof ans);
    cin>>q;
    while( q-- ) {
        int l , r;
        cin>>l>>r;
        cout<<getMax(l ,r)<<endl;
    }
    return 0;
}
