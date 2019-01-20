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
int n , l , r;
ll dp[MAX][5];
ll zero ,one ,two;

ll solve(int id , int rem) {
    rem%=3;

    if( id == n ) return (rem ==0 );

    ll &ret = dp[id][rem];
    if( ret != -1) return ret;

    ret = 0;

    ret =  (ret+ (zero * solve(id+1, rem ) )%MOD )%MOD;
    ret = ( ret + (one * solve(id+1 , rem+1 ) ) %MOD  ) %MOD;
    ret = ( ret + (two * solve(id+1 , rem+2)  )%MOD  )%MOD;
    return ret;
}

int main()
{
    cin>>n>>l>>r;

    zero = (r/3) - (l-1)/3;
    one= max(zero - 1 , 0LL);
    two = max(zero-1 , 0LL);

    for(int i = l ; i %3 != 0 && i <= r; i++ ) {
        if( i%3 == 1) one++;
        else if(i%3 == 2) two++;
    }

    if( zero >=1 )
    for(int i = r; i%3 != 0 && i>=l; i--) {
        if( i%3 == 1) one++;
        else if(i%3 == 2) two++;
    }

//    cout<<zero<<" "<<one<<" "<<two<<endl;


    memset(dp, - 1,  sizeof dp);
    cout<<solve(0 , 0)<<endl;
    return 0;
}
