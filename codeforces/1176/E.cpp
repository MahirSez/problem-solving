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
#define MAX         500005
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int col[MAX] , n ,m, t , rec[2];
vector<int>edg[MAX];

void reset() {
    
    for(int i =0 ; i <=n ; i++ ) {
        edg[i].clear();
        col[i] = -1;
    }
    rec[0] = rec[1] = 0;
}

void dfs(int node  , int c) {
    
    col[node] = c;
    rec[c] ++;
    
    for(auto x: edg[node]) {
        if(col[x] != -1) continue;
        dfs(x , c^1);
    }
}

int main()
{
    fastRead;
    cin>>t;
    while( t-- ) {
        cin>>n>>m;
        reset();
        for(int i = 0 ; i < m ; i++ ) {
            int u , v;
            cin>>u>>v;
            edg[u].push_back(v);
            edg[v].push_back(u);
        }
        
        dfs(1  , 1);
        
        int color = rec[0] < rec[1] ? 0 : 1;
        
        cout<<min(rec[0] , rec[1])<<'\n';
        
            
        for(int i = 1 ; i<= n ; i++ ) {
            if(col[i] == color ) cout<<i<<" ";
        }
        cout<<'\n';
    }
    
    return 0;
}