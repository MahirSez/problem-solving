#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        ll h , c , t;
        cin>>h>>c>>t;
        if(2*t <= (h+c)) {
            cout<<2<<'\n';
            continue;
        }
        
        ll x1 = (t-h)/(c + h -2*t);
        ll x2 = x1 + 1;
        
        ll ans1 = abs( (c + h-2*t)*x1 - t+h );
        ll ans2 = abs( (c + h-2*t)*x2 - t+h );
        
//        cout<<ans1<<" "<<ans2<<'\n';
        
        double t1 = 1.0*( (x1+ 1)*h + x1 * c)/(2*x1+ 1);
        double t2 = 1.0*( (x2+ 1)*h + x2 * c)/(2*x2+ 1);
        
//        cout<<t1<<" "<<t2<<'\n';
        
        if(fabs(t1-t) <= fabs(t2-t)) cout<<2*x1+1<<'\n';
        else cout<<2*x2+1<<'\n';
        
    }
    return 0;
    
    
}