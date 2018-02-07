#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS     1e-8
#define MAX     1000006
#define MOD     1000000007
using namespace std;
int n , m ;
double  ans=INF ,a , b;
int main()
{
    cin>>n>>m;
    for( int  i=0 ; i < n ;i++ ) {
        cin>>a>>b;
        if( a/ b < ans) ans = a/b;
    }
    ans *= m;
    cout<<setprecision(10) <<fixed<<ans<<endl;
    return 0;
}
