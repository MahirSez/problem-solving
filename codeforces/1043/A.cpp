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
int n , ara[1000];
int main()
{
    fastRead;
    cin>>n;
    int mx = 0;
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i];
        mx = max(mx , ara[i]);
    }
    while( 1) {
        int a = 0;
        int b = 0;
        for(int i = 0 ; i < n ; i++ ) {
            a += ara[i];
            b += (mx - ara[i]);
        }
        if( b > a) {
            cout<<mx<<endl;
            return 0;
        }
        mx++;

    }
}
