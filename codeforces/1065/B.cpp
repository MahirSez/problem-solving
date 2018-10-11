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
    ll ans1= max( 0LL , n - 2*m);
    ll ans2 = 0;
    for(ll i = 0; i<= n ;i++  ) {
        ll tmp = (i*(i-1)/2);
        if( tmp >= m ) {
            ans2 = i;
            ans2 = n - ans2;
            break;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}

