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
    // fastio;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        if(n ==1 ) cout<<0<<'\n';
        else if(n == 2) cout<<1<<'\n';
        else if(n <= 4 ) cout<<2<<'\n';
        else if(n%2) cout<<3<<'\n';
        else cout<<2<<'\n';
    }
    return 0;
    
}