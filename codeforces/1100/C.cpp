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
double n , r;
int main()
{
    cin>>n>>r;
    double A = (n-2)*PI/(2.0*n);
//    cout<<(1/cos(A))<<endl;
    double tmp = (1/cos(A)) - 1;
    tmp = r /tmp;
    cout<<setprecision(10)<<fixed<<tmp<<endl;
    return 0;
}
