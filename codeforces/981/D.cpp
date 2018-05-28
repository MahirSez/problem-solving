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
int  n , k , dp[100][100] ;
ll mask , ara[100];

int ok(int id ,int part) {

    if( id == n && part == k) {
        return 1;
    }
    if( id ==n || part == k ) {
        return 0;
    }
    int &ret = dp[id][part];
    if( ret != -1 ) return ret;

    ll sum = 0;
    ret = 0;
    for(int i = id ; i < n ; i++ ) {

        sum += ara[i];
        if( (sum & mask) == mask ) {
            ret |= ok(i+1 , part + 1 ) ;
        }
    }
    return ret ;
}

int main()
{
    cin>>n>>k;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    for(int i = 60 ; i >= 0 ; i--) {
        mask|=(1LL<<i);
        memset( dp , -1 ,sizeof dp);
        if( ok(0 , 0) == 0 ) {
            mask ^= (1LL<<i);
        }
    }
    cout<<mask<<endl;
    return 0;
}
