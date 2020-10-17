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
        string s;
        cin>>s;
        int ok1 = 0 , ok2 = 0;
        for(auto x : s) {
            if(x == '<') ok1 = 1;
            if(x == '>') ok2 = 1;
        }

        if(ok1 == 0 || ok2 == 0) {
            cout<<n<<'\n';
            continue;
        }
        int ans = 0;

        for(int i =0 ; i < n ; i++ ) {
            char c1 = s[i];
            char c2 = s[(i-1 + n)%n];
            if(c1 == '-' || c2 == '-') ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
    
}