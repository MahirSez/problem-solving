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
        int n, m;
        cin>>n>>m;

        string s;
        cin>>s;
        while(m--) {
            int l , r;
            cin>>l>>r;
            l--, r--;
            int ok = 0;
            for(int i = 0 ; i < l ; i++ ) {
                if(s[i] == s[l]) ok =1;
            }
            for(int i = r+1 ; i < n ; i++ ) {
                if(s[i] == s[r]) ok = 1;
            }
            if(ok) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;

    
    
}