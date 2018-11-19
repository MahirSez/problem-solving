#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<double,double>
#define INF     	1e18
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
double a , b ,c , x1 , y1 , x2 , y2;
pii p1 , p2 , p3 , p4 , A , B;


double dist(pii x , pii y) {
    return sqrt( (x.uu - y.uu)*(x.uu-y.uu) + (x.vv - y.vv)*(x.vv - y.vv) );
}
int main()
{
    cin>>a>>b>>c;
    cin>>x1>>y1>>x2>>y2;
    A = {x1 , y1};
    B = {x2 , y2};

    p1 = {x1 , -(a * x1 + c)/b};
    p2 = {-(b * y1+c)/a ,y1 };

    p3 = {x2 , -(a * x2 + c)/b};
    p4 = {-(b * y2+c)/a ,y2 };

    double ans = abs(A.uu - B.uu) + abs(A.vv - B.vv);

    ans = min( ans , dist(A , p1) + dist(p1 , p3) + dist(p3 , B));
    ans = min( ans , dist(A , p1) + dist(p1 , p4) + dist(p4 , B));
    ans = min( ans , dist(A , p2) + dist(p2 , p3) + dist(p3 , B));
    ans = min( ans , dist(A , p2) + dist(p2 , p4) + dist(p4 , B));
    printf("%0.10f\n",ans);
    return 0;
}
