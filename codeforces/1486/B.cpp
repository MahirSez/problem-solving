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
        int n;
        cin>>n;

        vector<ll>x(n) , y(n);
        for(int i =0; i< n; i++ ) {
            cin>>x[i]>>y[i];
        }
        sort(x.begin() , x.end());
        sort(y.begin() , y.end());


        if(n%2) cout<<1<<'\n';
        else {
            ll cnt1 = x[n/2] - x[n/2-1] + 1;
            ll cnt2 = y[n/2] - y[n/2-1] + 1;
            cout<<cnt1 * cnt2<<'\n';
        }

    }
    return 0;
}