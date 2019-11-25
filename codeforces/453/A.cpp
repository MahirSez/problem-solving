#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;


//double power(double a , int b) {
//
//    double p ;
//    if( b == 0) return 1.0;
//    p = ( power(a , b/2));
//    p = ( p * p) ;
//    if( b & 1 ) p = ( p * a) ;
//    return p;
//}
//

int main()
{
    double m , n;
    cin>>m>>n;
    
    double sum = 0;
    for(int i =1;  i< m ; i++ ) {
        
        double tmp = (i*1.0)/m;
        tmp = pow(tmp , n);
        sum += tmp;
    }
    
    sum = m - sum;
    cout<<setprecision(10)<<fixed<<sum<<'\n';
    return 0;
    
}
