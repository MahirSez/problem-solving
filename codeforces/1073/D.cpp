#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	2e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n;
ll t , ara[MAX] ;
int main()
{
    fastRead;
    ll mn = INF;
    cin>>n>>t;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i] , mn = min(mn , ara[i]);

    ll ans = 0;
    while( t >= mn ) {

        ll taken = 0 , cnt = 0;
        for(int i =0 ; i < n ; i++ ) {

            if( taken + ara[i] <= t) {
                taken += ara[i];
                cnt++;
            }
        }
        ans += cnt*(t/ taken);
        t %= taken;
    }
    cout<<ans<<endl;

}
