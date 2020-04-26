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
        ll x , y;
        ll a , b;
        cin>>x>>y>>a>>b;
        ll ans1 = min(x , y)*b + (max(x,y) - min(x,y) )*a;
        ll ans2 = x*a + y*a;
        cout<<min(ans1 , ans2)<<'\n';
        
    }
    return 0;
    
}