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

int on(ll x, ll k) {
    return (x & (1LL << k) );
}
int main()  {
    fastio;

    int t;
    cin>>t;

    while(t--)    {

        ll u, v;
        cin>>u>>v;

        if(u > v) {
            cout<<"NO\n";
            continue;
        }
        vector<int>v1, v2;
        for(int i =0; i < 31 ; i++ ) {
            if(u & (1<<i)) v1.push_back(i);
            if(v & (1<<i)) v2.push_back(i);
        }

        if(v2.size() > v1.size()) {
            cout<<"NO\n";
            continue;
        }
        int ok = 1;
        for(int i = 0; i < v2.size() ; i++) {
            if(v2[i] < v1[i]) ok = 0;
        }

        cout<<(ok ? "YES" : "NO")<<'\n';
    }
    return 0;
}
