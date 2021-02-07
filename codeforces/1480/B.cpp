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
        ll A, B, n;
        cin>>A>>B>>n;
        vector<ll>a(n), b(n), xx(n);
        ll mx = 0 , tot = 0;
        for(int i =0; i <n ; i++ ) cin>>a[i] , mx = max(mx, a[i]);
        for(int i =0; i <n ; i++ ) cin>>b[i];
        for(int i =0; i <n ; i++ ) {
            xx[i] = ( (b[i]-1)/A + 1) * a[i];
            tot += xx[i];
        }
        // cout<<tot<<'\n';
        if(B - tot + mx > 0) cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}