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

    ll x , k , d;
    cin>>x>>k>>d;
    x = abs(x);
    ll tmp = min(k , x/d );

    k -= tmp;

    x -= tmp * d;

    if(k%2) {
        x -= d;
        cout<<abs(x)<<'\n';
    }
    else cout<<x<<'\n';
    return 0;
    
    
}