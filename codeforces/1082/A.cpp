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
int t ;
int n , x , y , d;
int main()
{
    fastRead;
    cin>>t;
    while( t-- ) {
        cin>>n>>x>>y>>d;
        int ans = INF;
        if( abs(x - y) %d == 0) {
            ans = abs(x-y)/d;
        }

        if( (y-1)%d ==0 ) {

            ans = min( ans , (y-1)/d +( (x>1) ? ((x-2)/d + 1) : 0) );
        }
        if( (n-y)%d ==0 ) {
            ans = min(ans , (n-y)/d +( (x<n) ? ((n-x-1)/d + 1) : 0) );
        }
        if( ans ==INF) cout<<-1<<'\n';
        else cout<<ans<<'\n';
    }
    return 0;
}
