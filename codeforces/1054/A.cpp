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
int x , y , z, t1 , t2 , t3;
int main()
{
    cin>>x>>y>>z>>t1>>t2>>t3;
    int ans1 = abs(x - y) * t1;
    int ans2 = abs(x-z) * t2 + (abs(y-x)) * t2 + t3*3;
//    if( x == z) ans2 += t3*2;
//    cout<<ans1<<" "<<ans2<<endl;
    if( ans2 <= ans1) cout<<"YES"<<endl;

    else cout<<"NO"<<endl;
    return 0;

}
