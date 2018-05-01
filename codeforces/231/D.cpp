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
int ara[6] , x,y,z , a ,b,c ,ans;
int main()
{
    cin>>x>>y>>z;
    cin>>a>>b>>c;
    for(int i =0 ; i < 6 ; i++ ) cin>>ara[i];
    if( y < 0) ans += ara[0];
    else if( y > b) ans += ara[1];
    if( z < 0 ) ans += ara[2];
    else if( z > c) ans +=ara[3];
    if( x < 0) ans += ara[4];
    else if( x > a) ans += ara[5];
    cout<<ans<<endl;
    return 0;
}
