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
string str;

ll bigMod(ll a , ll b) {
    ll p ;
    if( b == 0) return 1;
    p = ( bigMod(a , b/2) % MOD );
    p = ( p * p) % MOD;
    if( b & 1 ) p = ( p * a) % MOD;
    return p;
}

ll solve(int id) {
    if(id == n) {
        return 0;
    }
    if( str[id] == '0') return (2*solve(id+1) % MOD ) ;
    return ( ( 2* solve(id+1)%MOD + bigMod(2 , 2*(n-1-id) ) ) % MOD );
}

int main()
{
    cin>>str;
    n = str.size();
    cout<<solve(0)<<endl;
    return 0;
}
