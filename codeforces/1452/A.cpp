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
    int t;
    cin>>t;
    while(t--) {
        int n , m;
        cin>>n>>m;
        if(n == m ) cout<<n+m<<'\n';
        else {
            int ans = 2*min(n, m) + 1;
            // cout<<" "<<ans<<'\n';
            int tmp = max(n , m) - ( min(n,m) + 1);
            ans += tmp*2;
            cout<<ans<<'\n';
        }
    }
    return 0;
}