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
#define MOD		1000000007
using namespace std;
ll n , a,b;
int main()
{
    scanf("%lld",&n);
    while( n-- ) {

        scanf("%lld %lld",&a,&b);
        ll x = a*b;
        ll ans = ceil(cbrt(x));

        if( ans * ans * ans != a *b  || a%ans || b%ans )
            printf("no\n");
        else printf("yes\n");
    }
    return 0;
}
