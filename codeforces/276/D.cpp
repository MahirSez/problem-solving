#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
ll a , b;
int main()
{
    cin>>a>>b;
    int id = -1  , ans = 0;
    for(int  i = 62 ; i >=0 ; i-- ) {

        if( (b & (1LL<<i)) && !(a & (1LL<<i)) ) {
            id = i+1;
            break;
        }
    }
    if( id == -1) cout<<0<<endl;
    else cout<<((1LL<<id)-1)<<endl;
    return 0;
}
