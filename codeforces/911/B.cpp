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
int n  ,a, b;
int ans = -1;
int main()
{
    cin>>n>>a>>b;
    for( int  i= 1; i <n ; i++ ) {

        int ans1 = (a/i);
        int ans2 = ( b/(n-i) );

        ans = max( ans, min( ans1 , ans2) );
    }
    cout<<ans<<endl;
    return 0;
}
