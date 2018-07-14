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
ll w , m , k;
int main()
{
    cin>>w>>m>>k;
    ll tmp = m;
    ll ans = 0 , ten = 1;
    int cnt = 0;
    while( tmp) {
        tmp /= 10;
        cnt++;
        ten *= 10;
    }
    while( 1 ) {
        ll nilam = ten - m;
        if ( w/(nilam*cnt) < k)  {
            cout<<ans + (w/(cnt*k))<<endl;
            return 0;
        }
        w -= nilam * k * cnt;
        ans += nilam;
        cnt++;
        m = ten;
        ten *= 10;
    }
    return 0;
}
