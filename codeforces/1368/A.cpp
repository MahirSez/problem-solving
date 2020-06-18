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
    int t;
    cin>>t;
    while(t--) {
        ll a, b, n;
        cin>>a>>b>>n;
        int ans = 0;
        while(max(a,b) <=n) {
            ll tmp = a + b;
            if(a > b) b = tmp;
            else a = tmp;
            ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}