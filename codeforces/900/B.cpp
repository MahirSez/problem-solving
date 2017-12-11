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
using namespace std;
int a , b , c;
int cnt,tmp;
int main()
{
    cin>>a>>b>>c;
    a*=10;

    for( int  i= 1 ; i <1000; i++ ) {

        tmp = a / b;

        do {

            if( tmp%10 == c) {

                cout<<i<<endl;
                return 0;
            }
            tmp /=10;
        } while( tmp );

        a %= b;
        a *=10;
//        cout

    }
    cout<<-1<<endl;
    return 0;
}
