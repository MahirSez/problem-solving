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


int ans[N];
int vis[N];

vector<int>vec;
string s;
int n;

void dfs(int node, int flg) {
    vec.push_back(node);
    vis[node] = 1;

    char c1 = '*' , c2 = '*';
    if(node > 0 ) {
        c1 = s[node-1];
        if(flg) c1 = c1 == 'L' ? 'R' : 'L';
    }
    if(node < n) {
        c2 = s[node];
        if(flg) c2 = c2 == 'L' ? 'R' : 'L';
    }


    if(c1 == 'L' && vis[node-1] ==0 ) dfs(node-1, flg^1);
    if(c2 == 'R' && vis[node+1] == 0) dfs(node+1, flg^1);


}

int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        cin>>n>>s;
        for(int i =0; i <=n ; i++ ) ans[i] = 0, vis[i] = 0;

        for(int i =0 ;i <=n ; i++ ) {
            if(ans[i]) continue;
            vec.clear();
            dfs(i,0);

            // cout<<i<<" --> ";
            // for(auto x : vec) cout<<x<<" ";
            // cout<<'\n';
            //
            for(auto x: vec) {
                if((x^i)%2 == 0) ans[x] = vec.size();
                vis[x] = 0;
            }
        }

        for(int i= 0; i<=n ; i++) cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
}