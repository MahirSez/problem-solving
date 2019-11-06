#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

int n , m;

set<int>edg[MAX] , unvisited;

int vis[MAX];

void dfs(int node) {

    vis[node] = 1;
    
    vector<int>cld;
    
    unvisited.erase(node);
    
    for(auto x: unvisited) {
        if(edg[node].find(x) == edg[node].end()) cld.push_back(x);
    }
    
//    cout<<node<<" -> ";
//    for(auto x : cld) cout<<x<<" ";
//    cout<<'\n';
//    
//    cout<<unvisited.size()<<'\n';
    
    for(auto x: cld ) unvisited.erase(x);
    
    for(auto x : cld) if(vis[x] == 0 ) dfs(x);
}


int main()
{
    fastRead;
    cin>>n>>m;
    
    while(m-- ) {
        
        int u , v;
        cin>>u>>v;
        edg[u].insert(v);
        edg[v].insert(u);
    }
    
    for(int i =1;  i<=n ; i++ ) unvisited.insert(i);
    
    int cnt = 0;
    
    for(int i =1 ; i <=n ; i++ ) {
        
        if(vis[i]) continue;
        cnt++;
        dfs(i);
//        for(int i =1 ; i <=n ; i++ ) cout<<vis[i]<<" ";
//        cout<<'\n';
    }
    cout<<cnt-1<<'\n';
    return 0;
    
}