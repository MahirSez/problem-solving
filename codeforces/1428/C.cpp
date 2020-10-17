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
        stack<int>st;
        reverse(s.begin() , s.end());

        for(auto x : s) {
            if(x == 'B') st.push(2);
            else {
                if(st.empty() || st.top() == 1 ) st.push(1);
                else if(st.top() == 2) st.pop();
                else assert(0);
            }
        }

        int ans = st.size();
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            if(st.empty()) continue;
            if(top == 2 && st.top() == 2) {
                ans -= 2;
                st.pop();
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}