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

vector<int>edg[MAX] , same[MAX];
int n , m , vis[MAX] , col[MAX];

vector<int>r , b;
int cnt;

bool ok;

void dfs(int node , int c) {
    
    vis[node]= 1;
    
    col[node] = c;
    if(c) r.push_back(node);
    else b.push_back(node);
    
    for(auto x : edg[node]) {
        
        if(col[x] == -1) dfs(x , c^1);
        else if(col[x] == c) ok = false;
    }
    
    for(auto x : same[node]) {
        
        if(col[x] == -1) dfs(x , c);
        else if(col[x] != c)  ok = false;
    }
}

int main()
{
    fastRead;
    cin>>n>>m;
    while(m-- ) {
        
        int u  , v , typ;
        cin>>u>>v>>typ;
        if(typ) {
            same[u].push_back(v);
            same[v].push_back(u);
        }
        else {
            edg[u].push_back(v);
            edg[v].push_back(u);
        }
    }
    memset(col , -1 , sizeof col);
    ok = true;
    
    for(int i =1 ; i <=n ; i++ ) {
        
        if(vis[i]) continue;
        cnt++;
        
        r.clear() , b.clear();
        dfs(i , 1);
    }
    
    if(!ok) {
        cout<<0<<'\n';
        return 0;
    }
    
    
    ll ret = 1;
    for(int i =1 ; i < cnt;  i++ ) ret = (ret *2)%MOD;
    cout<<ret<<'\n';
    
}