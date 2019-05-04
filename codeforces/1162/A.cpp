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
vector<int>v;
int n , l , r , x , m , h , ara[200];
int main()
{
    fastRead;
    cin>>n>>h>>m;
    for(int i = 1 ; i<= n ; i++ ) ara[i] = h;

    for(int i =0 ; i < m ; i++ ) {

        cin>>l>>r>>x;
        for(int j =  l ; j <=r ; j++ ) {
			ara[j] = min(x , ara[j]);
        }
    }

    ll ans = 0;
    for(int i =1 ; i<= n ; i++ ) {
		ans += 1LL * ara[i]*ara[i];
    }
    cout<<ans<<endl;
    return 0;
}
