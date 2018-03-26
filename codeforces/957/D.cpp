#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
ll n ,ara[MAX]  , ans, mx[MAX];
int main()
{
    fastRead;
    cin>>n;
    for(int  i =0 ; i < n ; i++) {
        cin>>ara[i];
    }
    for(int i =1 ; i < n ; i++) {

        mx[i] = max(ara[i], mx[i-1]);
    }

    for(int i = n-2 ; i>=0 ; i--) {

        mx[i] = max( mx[i] , mx[i+1] -1);
    }

    for(int  i = 0 ; i < n ; i++) {
        ans += mx[i] - ara[i];
    }
    cout<<ans<<endl;
    return 0;
}
