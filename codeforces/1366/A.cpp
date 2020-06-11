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
        
        ll a, b;
        cin>>a>>b;
        if(a > b) swap(a,b);
        ll k = min(b - a, a);
        
        ll ans = k;
        
        a -= k;
        b -= 2*k;
        
        ll tmp = min(a/3, b/3);
        
        a -= tmp*3;
        b -= tmp*3;
        
        
        ans += tmp*2;
        
        if(a>=1 && b >=2) ans++;
        else if(a>=2 && b >=1) ans++;
        
        
        
        cout<<ans<<'\n';
        
        
    }
    return 0;
    
}