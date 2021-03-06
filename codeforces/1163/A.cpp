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
int n , m , ara[MAX];
int main()
{
    fastRead;
    cin>>n>>m;
    if( m ==0 ) {
		cout<<1<<endl;
		return 0;
    }

    for(int i= 0 ; i < n ; i++ ) ara[i] = 1;

    int now = 0 , cnt = 0;

	for(int i =0 ; cnt<m ; i++ ) {
		i%=n;

		if(ara[i] ==0 ) continue;

		for(int j = i+1 ; ; j++ ) {

			j %=n;

			if( ara[j] ) {
				ara[j] = 0;
				cnt++;
				break;
			}
		}
	}
	int ans = 0;
	for(int i =0 ; i < n ; i++ ) {
		if( ara[i] && ara[(i+1)%n] ==0 ) ans++;
	}
	cout<<ans<<endl;
	return 0;

}
