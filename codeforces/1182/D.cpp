#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int  n ;
vector<int>edg[MAX];
int distdeg[MAX] , lvl[MAX] , mark[MAX] , deg[MAX];
int node1 , node2 , node3 , node4 , leaf[MAX]; 


void dfs1(int node , int par , int lev) {
    
    lvl[node] = lev;
    for(auto x : edg[node]) {
        if( x ==par) continue;
        dfs1(x , node , lev+1);
    }
}

void dfs2(int node , int par ) {
    
    for(auto x : edg[node]) {
        
        if(x == par) continue;
        dfs2(x , node);
    }
    
    for(auto x : edg[node]) {
        if( mark[x] ) mark[node] = 1;
    }
}

bool dfs3(int node , int par , int lev) {
    
    if( distdeg[lev] == -1 ) distdeg[lev] = deg[node];
    
    if( distdeg[lev] != deg[node]) return false;
    
    bool ok = true;
    
    for(auto x : edg[node]) {
        if( x== par) continue;
        ok &= dfs3(x , node , lev+1);
    }
    return ok;
    
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0  ; i < n -1 ; i++ ) {
        int u , v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    for(int i =1 ; i <= n ; i++ ) {
        if(deg[i] == 1) leaf[i] = 1,  node4 = i;
    }
    node1 = 1;
    node2 = 1;
    node3 = 1;
    dfs1(1 , -1 , 0);
    for(int i =1 ; i <= n ; i++ ) {
        if(lvl[i] > lvl[node1]) node1 = i;
    }
    dfs1(node1 , -1 , 0);
    for(int i =1 ; i <= n ; i++ ) {
        if(lvl[i] > lvl[node2]) node2 = i;
    }
    mark[node1] = 1;
    
    dfs2(node2 , -1);

    if(lvl[node2]%2 ==0 ) {
        int tgt = lvl[node2]/2;
        for(int i =1; i <= n ; i++ ) {
            if( mark[i] && lvl[i] == tgt) node3 = i;
        }
    }
    
    memset(distdeg , -1 , sizeof distdeg );
    bool ok1 = dfs3(node1 , -1 , 0);
    if(ok1) {
        cout<<node1<<endl;
        return 0;
    }
    
    memset(distdeg , -1 , sizeof distdeg );
    bool ok2 = dfs3(node2 , -1 , 0);
    if(ok2) {
        cout<<node2<<endl;
        return 0;
    }
    
    memset(distdeg , -1 , sizeof distdeg );
    bool ok3 = dfs3(node3 , -1 , 0);
    if(ok3) {
        cout<<node3<<endl;
        return 0;
    }
    
    dfs1(node3, -1 , 0);
    
    
    for(int i =1 ; i <= n ; i++ ) {
        if(lvl[i] < lvl[node4] && leaf[i]) node4 = i;
    }
    
    memset(distdeg , -1 , sizeof distdeg );
    bool ok4 = dfs3(node4 , -1 , 0);
    if( ok4) {
        cout<<node4<<endl;
        return 0;
    }
    
    cout<<-1<<endl;
    return 0;
    
}

/*
8
3 5
7 8
2 8
2 3
2 6
3 4
1 8
*/