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
        ll n, x;
        cin>>n>>x;
        vector<ll>vec(n);
        ll tot = 0;
        for(int i =0; i< n; i++ ) cin>>vec[i] ,tot += vec[i];

        ll mx = 0;
        for(auto xx : vec) {
            mx += (xx-1)/x + 1;
        }

        tot = (tot-1)/x + 1;

        cout<<tot<<" "<<mx<<'\n';
        
    }
    return 0;
}