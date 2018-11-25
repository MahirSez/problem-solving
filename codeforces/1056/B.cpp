#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll n , m;


int main()
{
    cin>>n>>m;
    if( m ==1 ) {
        cout<<n*n<<endl;
        return 0;
    }
    ll ans = 0;
    for(int i =1 ; i <= min(n,m) ; i++ ) {
        for(int j = 1; j <= min(n,m) ;j++) {
            if( (i * i + j * j )%m  ) continue;

            ll t1 = (n-i)/m + 1 ;
            ll t2 =  (n-j)/m +1;
            ans += (t1*t2);
        }
    }
    cout<<ans<<endl;
    return 0;
}
