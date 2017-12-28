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
int n;
int main()
{
    cin>>n;
    int ans = 0;
    while( n>0 ) {
        ans += n;
        n-=2;
    }
    cout<<ans<<endl;
    return 0;
}
