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
int t , n;
int main()
{
    fastRead;
    cin>>t;
    while( t-- ) {
        cin>>n;
        int cnt = __builtin_popcount(n);
        int ans = (1<<cnt);
        cout<<ans<<'\n';
    }
    cout<<endl;
    return 0;
}
