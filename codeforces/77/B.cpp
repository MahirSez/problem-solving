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
int n;
double a ,b;
int main()
{
    fastRead;
    cin>>n;
    while( n-- ) {
        cin>>a>>b;
        if( b ==0 ) {
            cout<<1<<'\n';
            continue;
        }
        if( a==0 ) {
            cout<<0.5<<'\n';
            continue;
        }
        double ans = a * b;
        if(a <= 4 * b) {
            ans += (a * a)/8.0;
        }
        else {
            ans += (ans - 2* b*b);
        }
        ans = ans / (2.00 * a * b);
        cout<<setprecision(10)<<fixed<<ans<<'\n';
    }
    return 0;
}
