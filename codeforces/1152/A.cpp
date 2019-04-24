#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("dull.in","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	10000007
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int  n, m, a[MAX] , b[MAX];
int main()
{
	fastRead;
	cin>>n>>m;
	int a0 = 0, a1 = 0;
    for(int i =0 ; i < n ; i++) {

		int tmp;
		cin>>tmp;
		if( tmp &1) a1++;
		else a0++;
    }
	int b0 = 0, b1 = 0;
    for(int i =0 ; i < m ; i++) {

		int tmp;
		cin>>tmp;
		if( tmp &1) b1++;
		else b0++;
    }

    cout<<min(a0,b1) + min(b0 , a1)<<endl;
    return 0;
}
