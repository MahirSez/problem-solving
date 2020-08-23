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
    string s;
    cin>>s;
    int rem = 0;
    for(auto x : s) {
        rem *=10;
        rem += (x-'0');
        rem %=9;
    }
    if(rem) cout<<"No\n";
    else cout<<"Yes\n";
    return 0;
    
}