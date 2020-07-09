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
    
    int n;
    ll ans = 0;
    cin>>n;
    for(int i =1 ; i <=n ; i++ ) {
        ll tmp = 1LL*i *(n-i+1);
        ans += tmp;
    }
    
    for(int i = 1 ; i < n ; i++ ) {
        int u, v;
        cin>>u>>v;
        
        if(u > v) swap(u, v);
        
        ll tmp = 1LL*u * (n -v + 1);
        ans -= tmp;
    }
    cout<<ans<<'\n';
    return 0;
    
}