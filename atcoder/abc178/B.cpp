#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
int main() {
    ll a , b , c , d;
    cin>>a>>b>>c>>d;
    ll x = a*c;
    ll y = a*d;
    ll z = b*c;
    ll p = b*d;
    cout<<max({x , y , z , p})<<'\n';
    return 0;
}