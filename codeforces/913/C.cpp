#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     4e18
#define EPS		1e-8
#define MAX		1000006
#define MOD		1000000007
using namespace std;

ll n , l , ara[100];
ll ans;
ll solve (ll id,ll left)
{
    if (id == -1) return 0;
    if ( left & (1<<id) )
        return  (ara[id] + solve(id-1 , left - (1<<id) ) );
    return  min( ara[id] , solve(id-1 , left) ) ;
}
int main()
{

    ios::sync_with_stdio(false);
    cin>>n>>l;
    for( int i =0 ; i < 35 ;i++ ) ara[i] = INF;
    for(int  i =0 ; i < n ; i++ )
        cin>>ara[i];
    for( int  i =1 ; i < 35 ; i++ )
        ara[i] = min(ara[i] , ara[i-1] *2 );
    cout<<solve(30 , l)<<endl;
    return 0;
}
