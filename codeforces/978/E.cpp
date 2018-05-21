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
ll n , w , ara[MAX];
int main()
{
    fastRead;
    cin>>n>>w;
    for(int  i=0 ; i < n ;i++ ) cin>>ara[i];
    ll mn = 0 , mx = 0;
    ll sum =0;
    for(int i =0 ; i < n ;i++ ) {
        sum += ara[i];
        mn = min( mn , sum);
        mx = max( mx , sum);
    }
    if( mx > w || abs(mn) >w ) {
        cout<<0<<endl;
        return 0;
    }
    ll ans = (w-mx) - abs(mn) + 1;
    cout<<max(ans , 0LL )<<endl;
    return 0;
}
