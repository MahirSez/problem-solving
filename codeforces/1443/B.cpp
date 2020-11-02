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
        ll a , b;
        cin>>a>>b;

        string s;
        cin>>s;
        int last = -1;
        vector<int>vec;

        for(int  i=0 ; i < s.size() ;i++ ) {
            if(s[i] == '0') continue;
            
            if(last == -1) {
                last = i;
                continue;
            }

            vec.push_back(i - last - 1);
            last = i;
        }
        if(last == -1) {
            cout<<0<<'\n';
            continue;
        }
        ll ans = a;

        for(auto x : vec) {
            ans += min(x*b , a);
        }
        cout<<ans<<'\n';
    }
    return 0;
    
}