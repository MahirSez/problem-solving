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
int n , m , tot1, tot2, tmp=1;
//16808 7
int conv(int x) {
    int ans = 0;
    while( x ) {
        x/=7;
        ans++;
    }
    return ans;
}

int solve(int id, int mask , int num) {

    if( id == tot1 + tot2) {
        return ( num % tmp <=m && num/tmp <=n );
    }

    int ans = 0;
    for( int i =0 ; i < 7 ; i++ ) {

        if( !(mask & (1<<i)) ) {
            ans += solve(id+1 , mask | (1<<i) ,  num *7 + i);
        }
    }
    return ans;
}

int main()
{
    cin>>n>>m;
    n--;
    m--;
    tot1 = conv(max( n , 1 ) );
    tot2 = conv(max( m , 1 ) );
    if( tot1 + tot2 > 7) {
        cout<<0<<endl;
        return 0;
    }
    for( int i =0 ; i< tot2 ; i++ )
        tmp *= 7;
    cout<<solve(0 , 0 , 0)<<endl;
    return 0;
}
