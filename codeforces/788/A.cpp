#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e12
#define EPS     1e-8
#define MAX     1000006
#define MOD     1000000007
using namespace std;
ll n , tmp[MAX] ,ans1 , ans2  ,mx = -INF , ara[MAX];
int main()
{
    cin>>n;
    for( int i =0 ; i < n ; i++ ) cin>>tmp[i];
    for( int  i =0 ; i < n-1 ; i++ )
        ara[i] = abs(tmp[i] - tmp[i+1]);

    for( int  i = 0 ; i < n ; i++ ) {

        if( i & 1) {
            ans1 += ara[i];
            ans2 -= ara[i];
        }
        else {
            ans2 += ara[i];
            ans1 -= ara[i];
        }

        mx = max( mx , max(ans1 , ans2) ) ;
        //cout<<ans1<<" "<<ans2<<" "<<mx<<endl;
        ans1 = max( 0LL , ans1 );
        ans2 = max( 0LL , ans2);
    }
    cout<<mx<<endl;
    return 0;
}
