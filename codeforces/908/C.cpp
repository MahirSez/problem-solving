#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<double,double>
#define INF     1e9
#define EPS		1e-8
#define MAX		100005
using namespace std;
int  n;
double r ;
vector<pii>v;
double ara[MAX];

bool safe( double x1 , double x2 ) {

    if( x1 > x2 )swap(x1,x2);

    if( x1 + 2*r < x2  ) return true;
    return false;
}

int main()
{
    cin>>n>>r;
    for( int  i =0 ; i < n ;i++) cin>>ara[i];

    v.push_back({ara[0] , r });

    for( int  i =1; i < n ; i++) {

        double mn = r;

        for( int j = 0;  j < i ; j++) {

            pii pt = v[j];

            if( safe( ara[j] , ara[i] ) ==true )
                continue;

            double tmp =  4 * r * r  - ( ara[i] - ara[j]) * ( ara[i] - ara[j]);
            tmp = sqrt(tmp);
            tmp += pt.vv;

            mn = max( mn , tmp);
        }

        v.push_back({ara[i] , mn });
    }

    for( int  i =0 ; i < v.size(); i++)
        printf("%.10lf ",v[i].vv);

    return 0;
}
