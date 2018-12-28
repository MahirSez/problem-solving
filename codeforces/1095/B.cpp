#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , ara[MAX];
int main()
{
    fastRead;
    cin>>n;
    for(int i = 0 ; i < n ; i++ ) cin>>ara[i];

    sort( ara  , ara + n);

    int mx = 0 , mn = INF;
    for(int i = 0 ; i < n-1 ; i++ ) {
        mx = max(ara[i] , mx);
        mn = min(ara[i] , mn);
    }
    int tmp1 = mx - mn;

    mx = 0 , mn = INF;
    for(int i = 1 ; i < n ; i++ ) {
        mx = max(ara[i] , mx);
        mn = min(ara[i] , mn);
    }
    cout<<min(tmp1 , mx - mn)<<endl;
    return 0;
}
