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
int n  , ax , ay , bx , by , cx , cy;
int main()
{
    cin>>n>>ax>>ay>>bx>>by>>cx>>cy;
    bool x = ((ax-bx) >0);
    bool y = ((ay-by) >0);

    bool xx = ((ax-cx)>0);
    bool yy = ((ay-cy)>0);
    if( x==xx && y==yy) {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}
