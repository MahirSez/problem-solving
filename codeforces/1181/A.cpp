#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("input.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("output.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll x , y , z;
int main()
{
    cin>>x>>y>>z;
    cout<<(x+y)/z<<" ";
    x%=z;
    y%=z;
    
    ll ans = INF;
    
    if( x + y < z) ans = 0;
    else {
        ll tmp = (x+y)%z;
        ans = min(x - tmp , y - tmp);
    }
    cout<<ans<<endl;
    
    return 0;
    
}