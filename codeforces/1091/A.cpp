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
int y , b , r;
int main()
{
    cin>>y>>b>>r;
    int ans = 0;
    for(int i =1 ; i<=100 ;i++) {

        if( i +2<= r && i+1<=b && i <=y) ans = max(ans , 3*i+3);
    }
    cout<<ans<<endl;
    return 0;
}
