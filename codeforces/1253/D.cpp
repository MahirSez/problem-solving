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

int n , m , col[MAX] , nowcol;

vector<int>edg[MAX];

priority_queue<int>pq;

void dfs(int node) {
    
    col[node] = nowcol;
    pq.push(node);
    for(auto x : edg[node ]) {
        if(col[x]) continue;
        dfs(x);
    }
}


ll solve(int node ){
    
    nowcol++;
    while(!pq.empty()) pq.pop();
    
    dfs(node);
    
    int frm = node , to = node;
    ll ret = 0;
    
    for(int i = frm ; i <= pq.top() ; i++ ) {
        
        
        if(col[i] == 0 ) dfs(i) , ret++;
        else {
            assert(col[i] == nowcol);
        }
    }
    
    return ret;
    
}


int main()
{
    fastRead;
    cin>>n>>m;
    while(m--) {
        
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    
    ll ans = 0;
    for(int i =1 ; i <=n ; i++ ) {
        
        if(col[i]) continue;
        ans += solve(i);
    }
    
    cout<<ans<<'\n';
    return 0;
    
}