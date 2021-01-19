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
        string s;
        cin>>n>>s;

        string ans = "";
        int last = -1;
        for(auto x : s) {
            int val = x - '0';
            if(val + 1 == last) {
                ans += '0';
                last = val;
            }
            else {
                ans += '1';
                last = val + 1;
            }
        }
        cout<<ans<<'\n';

    }
    return 0;
}