#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e18
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n;
ll s[5000] , c[5000];
ll ans = INF;
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>s[i];
    for(int i =0 ; i < n ; i++ ) cin>>c[i];
    for(int i =0 ; i < n ;i ++ ) {
        ll tmp1 = INF ,tmp2 = INF;
        for(int j = 0 ;j < i ; j++ ) {
            if( s[j] < s[i] ) {
                tmp1 = min( c[j] , tmp1);
            }
        }
        for(int j = i + 1 ; j < n ; j ++ ) {
            if( s[j] > s[i]) {
                tmp2 = min( c[j] , tmp2);
            }
        }
        if( tmp1 != INF && tmp2 != INF) ans = min(ans, tmp1 + tmp2 + c[i]);
    }
    if( ans !=INF) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}
