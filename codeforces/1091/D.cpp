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
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll n;
const ll mod = 998244353 ;
ll  fact[MAX] , perm[MAX];
int main()
{
    cin>>n;
    fact[0] = 1;
    for(int i = 1 ; i <= n ; i++) fact[i] = (i*fact[i-1])%mod;

    if( n ==1 ) {
        cout<<1<<endl;
        return 0;
    }
    else if( n ==2) {
        cout<<2<<endl;
        return 0;
    }

    ll tmp = n;
    perm[0]  =1 ;
    for(int i = 1 ; i <= n ; i++  ) {
        perm[i] = (perm[i-1] * tmp)%mod;
        tmp--;
    }

    ll ans = fact[n];

    for(int i = 1 ; i<= n-1 ; i++  ) {

        ll tmp = (perm[i] * (fact[n-i] + mod -1LL ) )%mod;
//        cout<<i <<" "<<tmp<<endl;
        ans = (ans + tmp)%mod;
    }
    cout<<ans<<endl;
    return 0;

}
