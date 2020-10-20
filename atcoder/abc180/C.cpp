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

const int N = 1e6 + 6;

int main()  {
    fastio;

    ll x;
    cin>>x;
    set<ll>s;
    for(ll i =1 ; i < N ; i++ ) {
        if(x%i) continue;
        s.insert(i);
        s.insert(x/i);
    }
    for(auto xx : s) cout<<xx<<'\n';
    return 0;
    
}