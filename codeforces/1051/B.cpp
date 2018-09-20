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
ll l , r;
int main()
{
    cin>>l>>r;
    cout<<"YES"<<endl;
    for(ll i = l ; i < r ; i+=2) {
        printf("%lld %lld\n",i , i +1);
    }
    return 0;
}
