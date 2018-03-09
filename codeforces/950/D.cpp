#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS     1e-8
#define MAX     1000006
#define MOD     1000000007
using namespace std;

ll n , q ,x;
ll solve(ll id) {

    if( id & 1) return ((id+1)/2);
    return solve(id + (n-id/2) );
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q;
    while( q-- ) {
        cin>>x;
        cout<<solve(x)<<endl;
    }
    return 0;
}

