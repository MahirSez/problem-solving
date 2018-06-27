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
ll n , m ;
ll ara[MAX] , odd[MAX] ,even[MAX];
int main()
{
    fastRead;
    cin>>n>>m;
    for(int i = 1 ; i<= n ;i++ ) cin>>ara[i];
    ara[++n] = m;
    for(int i =1 ; i <= n ;i++) {
        if( i & 1) odd[i] = ara[i] - ara[i-1];
        else even[i] = ara[i] - ara[i-1];
    }
    for(int i = 1 ; i<= n ; i++ ) {
        odd[i] += odd[i-1];
        even[i] += even[i-1];
    }
    ll ans = odd[n];
    for(int i =1 ; i<=n ; i++) {
        if( ara[i] == ara[i-1] + 1 ) continue;
        ans = max( ans , odd[i-1] + ara[i]- ara[i-1]-1 + even[n] - even[i]);
    }
    cout<<ans<<endl;
    return 0;
}
