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
ll n , prc[5] , ara[MAX] , ans[5];
int main()
{
    cin>>n;
    for(int i = 0 ; i < n ; i++ ) cin>>ara[i];
    for(int i =0 ; i < 5 ; i++ ) cin>>prc[i];
    ll tot = 0;
    for(int  i =0 ; i < n ;i++ )  {

        tot += ara[i];
        for(int j = 4 ; j>= 0 ; j--) {
            if( prc[j] <= tot) {

                ll tkn = tot/prc[j];
                ans[j] += tkn;
                tot -= prc[j] * tkn;
            }
        }
    }
    for(int i =0 ; i < 5 ; i++ ) cout<<ans[i]<<" ";
    cout<<endl<<tot<<endl;
    return 0;
}
