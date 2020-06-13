#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

vector<int>edg[MAX];
int col[MAX], vis[MAX];

vector<int>ind, cyc;

vector<int>r, g;

void dfs1(int node, int c) {
    
    bool ok = 1;
    for(auto x: edg[node]) {
        if(col[x] == c) ok = 0;
    }
    
    if(!ok) {
        col[node] = 3;
        return ;
    }
    
    col[node] = c;
    if(c == 1) r.push_back(node);
    else g.push_back(node);
    
    int cc = 1;
    if(c == 1) cc = 2;
    
    for(auto x : edg[node]) {
        if(col[x]) continue;
        dfs1(x, cc);
    }
}

int dfs2(int node, int p) {
    
    vis[node] = 1;
    bool ok = 0 ;
    
    for(auto x : edg[node]) {
        if(x == p) continue;
        if(vis[x] == 1) ok = 1;
    }
    if(ok) {
        cyc.push_back(node);
        return 1;
    }
    
    for(auto x : edg[node]) {
        if(vis[x]) continue;
        ok |= dfs2(x, node);
        if(ok) break;
    }
    if(ok) cyc.push_back(node);
    vis[node] = 2;
    
    return ok;
}

int main()
{
    fastRead;
    int n, m, k;
    cin>>n>>m>>k;
    for(int i =1; i <=m ; i++ ) {
        int u, v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    for(int i =1; i <=n ; i++ ) {
        if(col[i]) continue;
        r.clear();
        g.clear();
        dfs1(i, 1);
        if(r.size() < g.size()) swap(r, g);
        for(auto x : r) ind.push_back(x);
    }
    
//    for(auto x : ind)cout<<x<<" ";
//    cout<<'\n';
    
    if( ind.size() >= (k+1)/2 ) {
        
        cout<<1<<'\n';
        for(int i =0 ; i < (k+1)/2; i++ ) cout<<ind[i]<<" ";
        cout<<'\n';
        return 0;
    }
    
    for(int i =1;  i<=n ; i++ ) {
        if(col[i] != 3) continue;
//        cout<<" "<<i<<'\n';
        int ret = dfs2(i, -1);
        break;
    }
    cout<<2<<'\n';
    cout<<cyc.size()<<'\n';
    for(auto x : cyc) cout<<x<<" ";
    cout<<'\n';
    
    return 0;
}