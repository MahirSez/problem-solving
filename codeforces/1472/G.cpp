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

vector<int>edg[N], rev[N];
int dp[N][2];

int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        int n , m;
        cin>>n>>m;

        for(int i =1 ;i <=n ; i++ ) {
            edg[i].clear(), rev[i].clear();
            dp[i][0] = dp[i][1] = INF;
        }


        vector<int>vis(n+1), frm_root(n+1,-1);

        for(int i =0 ; i < m ;i++ ) {
            int u, v;
            cin>>u>>v;
            edg[u].push_back(v);
            
        }

        // for(int i = 1; i <=n ; i++ ) {
        //     cout<<i<<" -->\n";
        //     for(auto x : rev[i]) cout<<x<<" ";
        //     cout<<'\n';
        // }

        queue<int>q;
        stack<int>st;

        frm_root[1] = 0;
        q.push(1);
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            st.push(top);

            for(auto x : edg[top]) {    
                if(frm_root[x] != -1) continue;
                frm_root[x] = frm_root[top] + 1;
                q.push(x);
            }
        }
        for(int i =1 ; i<=n ; i++ ) dp[i][0] = frm_root[i];


        while(!st.empty()) {
            int top = st.top();
            st.pop();

            for(auto x : edg[top]) {
                if( frm_root[top] < frm_root[x]) {
                    dp[top][0] = min(dp[top][0], dp[x][0]);
                    dp[top][1] = min(dp[top][1], dp[x][1]);
                }
                else {
                    dp[top][1] = min(dp[top][1], dp[x][0]);
                }
            }
        }

        for(int i =1 ; i <= n ; i++ ) {
            cout<<min(dp[i][0], dp[i][1])<<" ";
        }
        cout<<'\n';
    }
    return 0;
}