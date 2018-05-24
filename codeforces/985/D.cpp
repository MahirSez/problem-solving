#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	5e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll n , h;

bool ok(ll mxH) {

    ll k = min( h , mxH );
    ll cnt = mxH * mxH - ((k *(k - 1))/2);
    return (cnt<=n);
}

ll get(ll mxH) {

    ll k = min( h , mxH );
    ll cnt = mxH * mxH - ((k *(k - 1))/2);
    ll len = (2 * mxH - 1) - (k-1);
    ll baki = n - cnt;
    return (len + ceil( baki*1.00/ mxH ) );
}

int main()
{
    fastRead;
    cin>>n>>h;
    ll lo = 1 , hi = INF;
    while( lo + 1< hi  ) {
        ll mid = (lo + hi)/2;
        if( ok(mid) ) {
            lo = mid;
        }
        else hi = mid;
//        cout<<hi<<" "<<lo<<" "<<mid<<endl;
    }
//    cout<<hi<<" "<<get(hi)<<endl;
//    cout<<lo<<" "<<get(lo)<<endl;
    if( ok(hi) ) cout<<get(hi)<<endl;
    else cout<<get(lo)<<endl;
    return 0;
}
