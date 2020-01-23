#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

vector<int>edg[MAX] ;
map<pii , int> mp;

int n , lvl[MAX] , mark[MAX];
vector<int>vec;

int ans;

void dfs1(int node, int lev) {
    
    
    lvl[node] = lev;
    
    for(auto x : edg[node]) {
        if(lvl[x]) continue;
        dfs1(x , lev+1);
    }
}


void dfs2(int node , int par , int tgt) {
    
    if(node == tgt) {
        mark[node]  = 1;
        vec.push_back(node);
        return;
    }

    
    for(auto x : edg[node]) {
        if(x == par) continue;
        
        dfs2(x , node , tgt);
        
        if(mark[x]) {
            mark[node] = 1;
            vec.push_back(node);
        }
    }
    
}


void dfs3(int node , int par , int lev) {

    lvl[node] = lev;
    
    for(auto x : edg[node]) {
        if(mark[x] || x == par) continue;
        
        dfs3(x , node , lev+1);
    }
}

int solve(int id1 , int id2) {
    
    
    
    dfs2(id1, -1 , id2);
    
    memset(lvl ,0 , sizeof lvl);
    for(int i =1; i <=n ; i++ ) {
        if(mark[i]) dfs3(i , -1 , 0);
    }
    int mx = -1 , id3 = -1;
    for(int i =1; i <=n ; i++) {
        
        if(lvl[i] > mx && i != id1 && i != id2) {
            mx = lvl[i];
            id3 = i;
        }
    }
    
    ans += mx;
    
    assert(id3 != id1 && id3 != id2);
    
    return id3;
    
    
}


int main() {
        
    fastRead;
    cin>>n;
    for(int i =1;  i < n ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    dfs1(1 , 1);
    int l = -1 , id1 = -1;
    
    for(int i =1; i <=n ; i++ ) {
        if(lvl[i] > l) {
            l = lvl[i];
            id1 = i;
        }
    }
    
    
    memset(lvl , 0 , sizeof lvl);
    dfs1(id1 , 1);
    
    l =0 ;
    int id2 = 1;
    for(int i =1; i <=n ; i++ ) {
        if(lvl[i] > l) {
            l = lvl[i];
            id2 = i;
        }
    }
    ans = l-1;
    
    int ret = solve(id1 , id2);
    cout<<ans<<'\n';
    cout<<id1<<" "<<id2<<" "<<ret<<'\n';
    
    return  0;
    
    
    
    
}