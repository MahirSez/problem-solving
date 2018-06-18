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
struct PT {
    double x , y;
};
PT a[4] , b[4];

double area(PT a , PT b , PT c) {
    return ( a.x * (b.y - c.y) - a.y *(b.x - c.x) + (b.x *c.y - b.y*c.x) );
}


bool inside(PT tgt , PT a , PT b , PT c , PT d ) {
    double a1 = fabs(area( a , tgt , d));
    double a2 = fabs(area( d , tgt , c));
    double a3 = fabs(area( c , tgt , b));
    double a4 = fabs(area( b , tgt , a));
    double b1 = fabs(area( a , b , d));
    double b2 = fabs(area( d , b , c));
    return ( (a1 + a2 + a3 + a4 - b1 - b2) < EPS);

}


int main()
{
    for(int i = 0 ; i < 4 ; i++ ) {
        cin>>a[i].x>>a[i].y;
    }
    for(int i = 0 ; i < 4 ; i++ ) {
        cin>>b[i].x>>b[i].y;
    }
    for(int i =0 ; i < 4 ; i++ ) {
        if(inside( b[i] , a[0] , a[1] , a[2] , a[3])) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    for(int i =0 ; i < 4 ; i++ ) {
        if(inside( a[i] , b[0] , b[1] , b[2] , b[3])) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    PT mid1;
    mid1.x = (a[0].x + a[2].x)/2.0;
    mid1.y = (a[0].y + a[2].y)/2.0;
    if( inside( mid1 , b[0] , b[1] , b[2] , b[3] )) {
        cout<<"YES"<<endl;
        return 0;
    }
    PT mid2;
    mid2.x = (b[0].x + b[2].x)/2.0;
    mid2.y = (b[0].y + b[2].y)/2.0;
    if( inside( mid2 , a[0] , a[1] , a[2] , a[3]) ) {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}
