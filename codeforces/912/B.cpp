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
ll mask=1 , n , k;
int main()
{
    cin>>n>>k;
    ll cnt = 1;
    while( 1) {

        if( (mask<<1) <=n ) {
            mask<<=1;
            cnt++;
        }
        else break;
    }
    mask<<=1;
    mask--;

    if( k == 1) cout<<n<<endl;
    else cout<<mask<<endl;
    return 0;
}
