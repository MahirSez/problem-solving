#include<bits/stdc++.h>
#define MAX 300005
#define INF 1e9
#define ll long long int 
using namespace std;

int n ,sz[MAX];
vector<int>edg[MAX];
int node ;
ll ans;

void dfs1(int node, int par) {
    
    sz[node] = 1;
    for(auto x : edg[node]) {
        if(x == par) continue;
        dfs1(x , node);
        sz[node] += sz[x];
    }
}


void dfs2(int node ,int par, ll tot) {
    
    ans = max(ans , tot);
    
    for(auto x : edg[node]) {
        
        if( x== par) continue;
        dfs2(x , node , tot + n - sz[x] *2);
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    
    for(int i =1 ; i < n ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    dfs1(1 , -1);
    ll tot = 0;
    for(int i =1 ; i <= n ; i++ ) tot += sz[i];
    
    dfs2(1 , -1 , tot);
    
    cout<<ans<<'\n';
    return 0;
}