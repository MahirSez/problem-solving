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
ll n ;

bool ok(ll x ){
    ll xx = 0 , ten = 0;
    ll tmp = n;
    while( tmp > 0) {
        if( x < tmp) {
            xx += x;
            tmp -=x;
        }
        else {
            xx += tmp;
            break;
        }
        if( tmp <= 0) break;
        ten += (tmp/10);
        tmp -=(tmp/10);
    }
    return ( xx >= ten);
}

int main()
{
    cin>>n;
    ll hi = n , lo = 1;
    ll ans = 1;
    while( hi > lo) {
        ll mid = (hi + lo) /2;
        if( ok(mid) ) {
            ans = mid;
            hi = mid ;
        }
        else {
            lo = mid + 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
