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
ll l , r , dp[20][2][10];
int n;
vector<int>v;

ll solve(int id , int isSmall, int shuru) {

    if(id == n-1) {
        if( !shuru ) return 0;
        if( isSmall) return 1LL;
        if( shuru <= v[n-1] ) return 1LL;
        return 0;
    }
    ll &ret = dp[id][isSmall][shuru];
    if( ret != -1 ) return ret;
    int till;
    if( isSmall ) till = 9;
    else till = v[id];
    ret = 0;
    if( shuru == 0 ) ret += solve(id+1 , 1 , 0 );

    for(int i = 0 ; i<= till ; i++ ) {

        if( i <till || isSmall) {
            if( shuru ==0  ) {
                if( i )ret += solve(id+1 , 1 , i );
            }
            else ret += solve(id+1 , 1 , shuru);
        }
        else {
            if( shuru ==0 ) {
                if( i) ret += solve(id+1 , 0 , i);
            }
            else ret += solve(id+1 , 0 , shuru);
        }
    }
    return ret;
}


ll call(ll x) {

    if( x < 0 ) return 0;
    if(x < 10)  return x;
    v.clear();
    while( x ) {
        v.push_back(x%10);
        x /= 10;
    }
    reverse( v.begin() , v.end() );
    n = v.size();
    return solve(0 , 0 , 0 ) + 9;
}

int main()
{
    cin>>l>>r;
    memset(dp, -1 , sizeof dp);
    ll frm = call(l-1);
    memset(dp , -1 , sizeof dp);
    ll to = call(r);
    cout<<to-frm<<endl;
    return 0;
}
