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
    int t;
    cin>>t;
    while(t-- ) {
        ll n , k;
        cin>>n>>k;
        vector<int>vec(n) , rec(n);
        int mx = -INF;

        for(int i =0 ; i < n ; i++ ) {
            cin>>vec[i];
            mx = max(mx , vec[i]);
        }

        k--;
        for(int i =0 ; i < n ; i++ ) vec[i] = mx - vec[i];

        mx = -INF;
        for(auto x : vec) mx = max(mx , x);

        for(auto x : vec) {
            if(k%2) cout<<mx - x<<" ";
            else cout<<x<<" ";
        }
        cout<<'\n';
        
    }
    return 0;
}