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
    string s, t;
    cin>>s>>t;
    
    int ans = INF;

    for(int i =0; i + t.size()- 1 < s.size() ; i++ ) {
        int cnt = 0;
        for(int j = i , k = 0 ; k < t.size() ; k++ , j++) {
            if(s[j]!= t[k]) cnt++;
        }
        ans = min(ans , cnt);
    }
    cout<<ans<<'\n';
    return 0;
    
    
}