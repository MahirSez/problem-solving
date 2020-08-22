#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;
vector<int>edg[N];
int col[N];

int ok;

vector<int>ans[2];

void dfs(int node , int c) {
    
    col[node] = c;
    ans[c].push_back(node);

    for(auto x : edg[node]) {
        if(col[x] == c) ok = 0;
        if(col[x] == -1) dfs(x , c^1);
    }

    

}

int main()  {
    fastio;
    int n, m;
    cin>>n>>m;

    ok = 1;
    memset(col , -1 , sizeof col);

    while(m--) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }

    for(int i =1 ; i <=n ; i++ ) {
        if(col[i] ==-1) dfs(i , 1);
    }
    if(ok==0) {
        cout<<-1<<'\n';
        return 0;
    }
    for(int i =0 ; i <= 1; i++ ) {
        cout<<ans[i].size()<<'\n';
        for(auto x : ans[i]) cout<<x<<" ";
        cout<<'\n';
    }
    

    return 0;
}