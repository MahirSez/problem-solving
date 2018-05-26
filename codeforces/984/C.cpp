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
ll n , p , q , b;
int main()
{
    fastRead;
    cin>>n;
    while( n-- ) {
        cin>>p>>q>>b;
        if(  p== 0 ) {
            cout<<"Finite"<<endl;
            continue;
        }
        ll g = __gcd(p,q);
        q/=g;
        while(1) {
            b = __gcd(q,b);
            q/=b;
            if( b == 1 ) break;
        }
        if( q==1 ) {
            cout<<"Finite"<<endl;
            continue;
        }
        else {
            cout<<"Infinite"<<endl;
            continue;
        }
    }
}
