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
        ll w , h , n;
        cin>>w>>h>>n;
        ll cnt1 = 1 , cnt2 = 1;
        while(w%2 ==0 ) {
            cnt1*=2;
            w/=2;
        }
        while(h%2 == 0) {
            cnt2*=2;
            h/=2;
        }

        cout<<(cnt1*cnt2 >= n ? "YES" : "NO")<<'\n';
    }
    return 0;
}