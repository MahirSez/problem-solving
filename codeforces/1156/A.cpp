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
int n , ara[MAX];
int main()
{
    int ans = 0;
    cin>>n;
    for(int i =0 ; i < n ; i++) cin>>ara[i];

    for(int i = 1 ; i < n ; i++ ) {

        if( ara[i] + ara[i-1] == 5) {
			cout<<"Infinite\n";
			return 0;
        }

        if( ara[i] + ara[i-1] == 3) ans +=3;
        else ans += 4;

        if( ara[i-1] == 3 && ara[i] == 1 && ara[i+1] == 2) ans--;
    }
	cout<<"Finite\n";
	cout<<ans<<endl;
	return 0;
}
