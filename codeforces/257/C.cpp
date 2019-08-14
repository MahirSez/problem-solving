#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e5 + 5;
const double PI  = acos(-1);

vector<double>vec;


double getAngle(double x , double y) {


    
    if( x == 0) {
        
        if( y > 0 ) return 90;
        return 270;
    }
    if(y ==0 ) {
        
        if( x > 0  ) return 0;
        return 180;
    }
    
    double angle = 0;
    if( x > 0 ) {
        
        if( y > 0) angle  =  atan(y/x) ;
        else angle  =  2*PI - atan( (-1.0*y) / x);
    }
    else {
        if( y > 0 ) angle = PI - atan(y / (-1.0*x) );
        else angle = PI + atan(  (-1.0*y) / (-1.0*x ) );
    }
    
    return (angle * 180.0)/PI;
    
}

int main()
{
    fastRead;
    int n ;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        
        double x , y;
        cin>>x>>y;
        
        vec.push_back(getAngle(x,y));
    }
    if( n ==1 ) {
        cout<<0<<endl;
        return 0;
    }
    
    sort(vec.begin() , vec.end());
    
    double gap = 0;
    for(int i =0 ; i < n-1 ; i++ ) {
        
        gap = max(gap , vec[i+1] - vec[i]);
    }
    
    gap = max(gap , 360.0 - vec[n-1] + vec[0]);
    
    double ans = 360.0 - gap;
    printf("%0.9f\n",ans);
    return 0;
    
}
    