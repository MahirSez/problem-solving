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
        string s;
        cin>>s;
        int a = 0 , b = 0 , ans = 0;
        for(auto x : s) {
            if(x == '(') a++;
            else if(x == '[') b++;
            else if(x == ')' and a >0) {
                ans++;
                a--;
            }
            else if(x == ']' and b > 0) {
                b--;
                ans++;
            }

            // cout<<a<<" "<<b<<" "<<ans<<'\n';

        }
        cout<<ans<<'\n';
    }
    return 0;
}