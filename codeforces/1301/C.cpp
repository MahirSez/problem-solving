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
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        ll n , m;
        cin>>n>>m;
        

        
        ll tot = n * (n+1)/2;
        
        ll zero = n - m ;
        
        ll per = zero / (m+1);
        
        ll baki = zero%(m+1);
        
        ll perdibe = m + 1 - baki;
        
        ll perplusonedibe = baki;
        
        
        ll tmp1 = per*(per+1)/2 * perdibe;
        
        ll tmp2 = (per+1) * (per+2)/2 * perplusonedibe;
        
        cout<<tot - tmp1 - tmp2<<'\n';
        
    }
    return 0;
    
}