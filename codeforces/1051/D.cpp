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
#define MOD     	998244353
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , k , dp[2000][2000][2][2];


int get(int a , int b , int i , int j) {

    if(a==b) {
        if(i==j) {
            if( i==a) return 0;
            return 1;
        }
        return 1;
    }

    if( i==j) return 0;

    if( i ==a ) return 0;
    return 2;
}

int solve(int col , int comp , int a , int b) {

    if( comp > k) return 0;
    if( col == n) return comp == k;
    int &ret = dp[col][comp][a][b];

    if( ret != -1 ) return ret;
    ret = 0;

    if( col ==0 ) {
        ret = (ret + solve(1 , 1 , 1 , 1)%MOD) % MOD;
        ret = (ret + solve(1 , 2 , 0 , 1)%MOD) % MOD;
        ret = (ret + solve(1 , 2 , 1 , 0)%MOD) % MOD;
        ret = (ret + solve(1 , 1 , 0 , 0)%MOD) % MOD;
    }

    else {

        for(int i =0 ; i < 2 ; i++) {
            for(int j =0 ; j < 2 ; j++ ) {
                ret = (ret +solve(col +1 , comp + get(a , b , i , j)  , i , j)%MOD )%MOD;
            }
        }
    }
    return ret;
}


int main()
{
    cin>>n>>k;
    memset(dp , -1 , sizeof dp);
    cout<<solve(0 , 0 , 0 , 0)<<endl;
    return 0;
}
