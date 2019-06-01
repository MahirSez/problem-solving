#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll a , b , c;
int main()
{
    cin>>a>>b>>c;
    ll ans = c*2;
    ll tmp = min(a,b);
    ans += tmp*2;
    a-=tmp;
    b-=tmp;
    if( a > 0 || b > 0 ) ans++;
    cout<<ans<<endl;
    return 0;
    
}