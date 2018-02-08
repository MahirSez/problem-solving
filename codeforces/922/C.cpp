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
#define MAX     50000007LL
#define MOD     1000000007
using namespace std;
ll n  ,k;
int main()
{
    scanf("%lld %lld",&n,&k);
    if( k ==1 || (n==1 && k==2) ) {
        printf("Yes\n");
        return 0;
    }
    if( k >=n ) {
        printf("No\n");
        return 0;
    }
    k = min(k , MAX);
    for(int  i =1 ; i <= k; i++  ) {

        if( (n% i) != i-1 ) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
