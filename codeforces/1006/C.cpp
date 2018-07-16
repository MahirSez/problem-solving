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
int n ;
ll ara[MAX] , a , c;
int main()
{
    fastRead;
    cin>>n;
    for(int  i=1 ; i <= n ; i++ )cin>>ara[i];
    ll l = 0 , r=  0;
    int lid = 0 , rid = n+1;
    while( lid  <= rid) {
//        cout<<lid<<" "<<rid<<" "<<l<<" "<<r<<endl;
        if( l < r) {
            l += ara[lid];
            lid++;
        }
        else {
            r += ara[rid];
            rid--;
        }
        if( l == r) a = l;
    }

    cout<<a<<endl;
    return 0;
}
