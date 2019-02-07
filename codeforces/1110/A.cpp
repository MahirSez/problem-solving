#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int b , k ;
int main()
{
    fastRead;
    cin>>b>>k;
    b &=1;
    int ans = 0;
    while( k--) {
        int tmp;
        cin>>tmp;
        if( k) ans += tmp*b;
        else ans += tmp;
    }
    if(ans &1) cout<<"odd"<<endl;
    else cout<<"even"<<endl;
    return 0;
}