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
ll n , m , a ,b;
int main()
{
    cin>>n>>m>>a>>b;
    ll tmp1 = (n%m)*b;
    ll tmp2 = (ceil(n*1.00/m)*m - n)*a;
    cout<<min(tmp1 , tmp2)<<endl;
    return 0;
}
