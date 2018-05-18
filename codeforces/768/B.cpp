#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
ll n , l , r;

ll cnt(ll x) {
    if( x <=1) return 1;
    return (2 * cnt(x/2) + 1);
}

ll solve(ll tgt , ll pos) {

    if( tgt<=1 ) return tgt;
    ll len = cnt(tgt);
    if( pos<= len/2) return solve( tgt/2 , pos);
    if( pos == len/2 + 1) return (tgt&1);
    return solve(tgt/2 , pos - len/2 -1);
}

int main()
{
    cin>>n>>l>>r;
    ll ans = 0;
    for(ll i = l ; i <=r ; i++) {
        ans += solve(n , i);
    }
    cout<<ans<<endl;
    return 0;
}
