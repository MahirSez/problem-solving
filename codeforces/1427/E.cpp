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


vector<string>ans;

ll Xor(ll a , ll b) {
    ans.push_back(to_string(a)  + " ^ " + to_string(b) );
    return a ^ b;
}
ll Add(ll a , ll b) {
    ans.push_back(to_string(a)  + " + " + to_string(b) );
    return a + b;
}
int main()  {
    fastio;

    ll x;
    cin>>x;

    if(x % 4 == 3) {
        ll x_2 = Add(x , x);
        x = Xor(x , x_2);
    }

    ll pw = x;

    for(int i =0 ; i < 30 ; i++ ) pw = Add(pw , pw);

    ll now = x;

    for(ll i = 1;  i< 30 ; i++ ) {
        if(now & (1LL<<i)) {
            now = Xor(now , x<<i);
        }
    }

    ll val1 = Add(now , x);
    ll val2 = Xor(now , x);
    ll two = Xor(val1 , val2);

    assert(two == 2);

    for(int i = 1; i < 30 ; i++ ) {
        if(x & (1LL<<i)) {
            x = Xor(x , two);
        }
        two = Add(two , two);
    }

    assert(x == 1);
    cout<<ans.size()<<'\n';

    for(auto xx : ans) cout<<xx<<'\n';
    return 0;

    
    
}