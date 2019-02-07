#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int q ;
ll n;

ll solve(ll tmp) {

    ll ans = 0;
    for(int i =1 ; i<=sqrt(tmp) + 5 && i<n; i++) {


        if(tmp %i ) continue;
        // cout<<i<<endl;
        ll a = (i^n);
        ll b = (i&n);

        ans = max( ans , __gcd(a,b));
        if( (n/i) < n) {
            a = ((n/i) ^ n);
            b = ((n/i) & n);
            ans = max( ans , __gcd(a,b));
        }
    }
    return ans;

}


int main()
{
    fastRead;
    cin>>q;
    while( q--) {
        cin>>n;
        ll tmp;
        tmp = n;
        int cnt =0;
        int zero = 0;
        while( tmp) {
            if( (tmp&1) == 0)  zero++;
            cnt++;
            tmp>>=1;
        }
        tmp = n;
        
        if( zero ==0 ) {
            cout<<solve(tmp)<<'\n';
        }
        else cout<<(1<<cnt)-1<<'\n';
    }
    return 0;
}