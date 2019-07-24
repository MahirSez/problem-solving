#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000006
using namespace std;
int t , n ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while( t--) {

        int loX = -1e5;
        int loY = -1e5;
        int hiX = 1e5;
        int hiY = 1e5;

        bool ok = true;
        cin>>n;
        while(n--) {

            int x , y;
            cin>>x>>y;

            int a , b , c , d;
            cin>>a>>b>>c>>d;

            if( a ==0 ) {

                loX = max(loX , x);
            }
            if( b ==0 ) {

                hiY = min(hiY , y);
            }
            if( c== 0) {

                hiX = min(hiX , x);

            }
            if( d ==0 ) {

                loY  = max(loY , y);
            }
        }



        if( loX > hiX || loY > hiY) {

            cout<<"0\n";
            continue;
        }

        cout<<1<< " "<<loX<<" "<<loY<<'\n';
    }
    return 0;
}
