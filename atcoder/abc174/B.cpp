#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;
    ll n , d;
    cin>>n>>d;
    d*=d;
    int ans = 0;

    for(int i =0 ; i < n ; i++ ) {
        ll x , y;
        cin>>x>>y;
        ll tmp = x*x + y*y;
        if(tmp <= d) ans++;
    }
    cout<<ans<<'\n';
    return 0;
}