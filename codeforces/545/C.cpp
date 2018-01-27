#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     2e9
#define EPS     1e-8
#define MAX     1000006
#define MOD     1000000007
using namespace std;
int n , h[MAX], x[MAX];

int main()
{
    cin>>n;
    for( int i =0 ; i < n ; i++ ) {
        cin>>x[i]>>h[i];
    }

    int last = x[0];
    int ans = 2 ;
    for( int  i=1 ; i < n-1 ; i++ ) {

        if( x[i] - h[i] > last) {
            ans++;
            last = x[i];
        }
        else if( x[i] + h[i] < x[i+1] ) {
            ans++;
            last = x[i] + h[i];
        }
        else last = x[i];
    }
    if( n <2) cout<<n<<endl;
    else cout<<ans<<endl;
    return 0;
}
