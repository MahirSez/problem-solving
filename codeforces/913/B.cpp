#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS		1e-8
#define MAX		1000006
#define MOD		1000000007
using namespace std;
int n , ara[1001][1001], par[1001];
bool nonlf[10000];
int main()
{
    cin>>n;
    for( int i = 2 ; i<=n ; i++) {

        int tmp,tmp1;
        cin>>tmp;
        nonlf[tmp] = true;
        par[i] = tmp;
        ara[tmp][i] = 1;
        tmp1 = par[tmp];
        ara[tmp1][tmp] = 0;
    }
    bool flg = true;
    for( int  i = 1 ; i <= n; i++) {
        int ans = 0;
        for( int j = 1 ; j<= n ;j++ ) {

            ans +=ara[i][j];
        }
        if(nonlf[i] && ans<3 ) flg  = false;
    }
    if( flg) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
