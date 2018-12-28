#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	998244353
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int t;
int n;
int main()
{
    fastRead;
    cin>>t;
    while( t-- ) {
        cin>>n;
        int tmp = __gcd(n , 180);
        int ans = 180/tmp;

        int seg = n/tmp;

        if( ans -2 >= seg) cout<<ans<<'\n';
        else {
            if( ans* 2 <= 998244353 ) cout<<ans*2<<'\n';
            else cout<<-1<<'\n';
        }
    }
    return 0;
}
