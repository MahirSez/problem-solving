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
double cx , cy , px , py , R , r , a , rad , ansx , ansy;
int main()
{
    cin>>R>>cx>>cy>>px>>py;
    double d = sqrt( (cx - px) * (cx - px) + (cy - py) * (cy - py));
    if( d == 0 ) {

        rad = R/2.00;
        cout<<setprecision(10)<<fixed<<(cx + rad)<<" "<<cy<<" "<<rad<<endl;
    }
    else if( d>= R) {

        cout<<setprecision(10)<<fixed<<cx<<" "<<cy<<" "<<R<<endl;
    }
    else {

        rad = (R + d) /2.00;
        double a = rad - d;
        ansx = ( a * px - rad * cx)/ (a - rad);
        ansy = ( a * py - rad * cy)/ (a - rad);
        cout<<setprecision(10)<<fixed<<ansx<<" "<<ansy<<" "<<rad<<endl;
    }
    return 0;
}
