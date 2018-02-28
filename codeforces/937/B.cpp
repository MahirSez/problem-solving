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
int p , y;
int main()
{

    cin>>p>>y;

    for(int i = y ; i >p ; i-- ) {
        bool flg = true;
        for( int j = 2; j <= p && j*j<= i; j++ ) {

            if( i %j ==0 ) {
                flg = false;
                break;
            }
        }
        if( flg ) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
