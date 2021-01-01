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
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n ; i++ ) {
            if(s[i] == '*') continue;
            if( i + 1 < n && s[i] == s[i+1] ) ans++ , s[i+1] = '*' ;
            if(i + 2 < n && s[i] == s[i+2]) ans++ , s[i+2] = '*';
        }
        cout<<ans<<'\n';
    }
    return 0;

}