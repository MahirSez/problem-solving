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
int main() {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        s += '*';
        int cnt = 1;
        vector<int>vec;

        for(int i = 1 ; i <=n ; i++ ) {
            if(s[i] == s[i-1]) cnt++;
            else {
                vec.push_back(cnt);
                cnt = 1;
            }
        }

        // for(auto x : vec) cout<<x<<" ";
        // cout<<'\n';
        //
        queue<int>q;

        for(int i =0 ; i < vec.size() ; i++) q.push(i);

        int ans= 0;
        for(int i =0 ; i < vec.size() ; i++ ) {



            while(!q.empty()) {
                if(q.front() < i) q.pop();
                else if(vec[q.front()] == 1) q.pop();
                else break;
            }
            ans ++;

            if(q.empty()) {
                i++;
                continue;
            }

            int top = q.front();

            // cout<<i<<" "<<top<<'\n';
            vec[top]--;

        }

        cout<<ans<<'\n';
    }
    return 0;
}