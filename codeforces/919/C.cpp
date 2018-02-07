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
int n , m, k ,ans;
string str[5000];
int main()
{

    cin>>n>>m>>k;
    for( int  i =0 ; i < n ; i++)
        cin>>str[i];

    for( int  i =0 ; i < n ; i++ ) {
        int cnt = 0;
        for( int  j= 0 ; j< m; j++ ){

            if( str[i][j] == '*' ) {
                ans += max( cnt - k +1 , 0);
                cnt = 0;
            }
            else cnt++;
        }
        ans += max( cnt - k +1 , 0);
    }
    for( int  i =0 ;k!= 1 && i < m ; i++ ) {
        int cnt = 0;
        for( int  j= 0 ; j< n; j++ ){

            if( str[j][i] == '*' ) {
                ans += max( cnt - k +1 , 0);
                cnt = 0;
            }
            else cnt++;
        }
        ans += max( cnt - k +1 , 0);
    }
    cout<<ans<<endl;
    return 0;
}
