#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pll         pair<ll,ll>
#define plp         pair<ll,pll>
#define INF         1e18
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
ll n , m , k , q , dist[MAX] , par[MAX] , lvl[MAX];
vector<plp>vec;
vector<pll>edg[MAX];

ll ptable[MAX][20] , wtable[MAX][20];


void dijk() {

    for(int i =k+1 ; i <=n ; i++ ) dist[i] = INF;
    
    priority_queue<pll>pq;
    
    for(int i =1; i <=k ; i++ ) pq.push({0 , i});
    
    while(!pq.empty()) {
        
        ll node = pq.top().vv;
        ll wt = -pq.top().uu;
        
        pq.pop();
        
        if(wt != dist[node]) continue;
        
        for(auto x : edg[node]) {
            
            ll xx = x.vv;
            ll ww = x.uu;
            
            if(dist[xx] > ww + wt ) {
                dist[xx] = ww + wt;
                pq.push({-dist[xx] , xx});
            }
        }
    }
}

ll boss(ll x) {

    return (par[x] == x) ? x : (par[x] = boss(par[x]) );
}

void dfs(int node , int p , int lev)  {
    
    lvl[node] = lev;
    for(auto x : edg[node]) {
        
        if(x.vv== p) continue;
        
        ptable[x.vv][0] = node;
        wtable[x.vv][0] = x.uu;
        dfs(x.vv , node , lev+1);
        
    }
}


ll query(int u , int v) {

    if(lvl[u] < lvl[v]) swap(u , v);
    
    ll ret = 0;
    
    while(lvl[u] > lvl[v]) {
        
        int logval = log2(lvl[u] - lvl[v]);
        ret = max(ret , wtable[u][logval] );
        u = ptable[u][logval];
    }
    
    if(u == v ) return ret;
    
    for(int logval = log2(lvl[u]) ; logval >=0 ; logval--) {
        
        if(ptable[u][logval] != -1 && ptable[u][logval] != ptable[v][logval]) {
            
            ret = max(ret , wtable[u][logval]);
            ret = max(ret , wtable[v][logval]);
            
            u = ptable[u][logval];
            v = ptable[v][logval];
        }
    }
    
    return max(ret , max(wtable[u][0] , wtable[v][0] ) );
}

int main()
{
    fastRead;
    cin>>n>>m>>k>>q;
    while(m--) {
        
        ll u , v , w;
        cin>>u>>v>>w;
        edg[u].push_back({w , v});
        edg[v].push_back({w , u});
        vec.push_back({w , {u , v}});
    }
    
    dijk();
    
    for(auto &x : vec) {
        x.uu += dist[x.vv.vv] + dist[x.vv.uu];
    }
    
    sort(vec.begin() , vec.end());
    
    for(int i = 1; i <=n ; i++ ) par[i] = i;
    
    for(int i= 1; i <=n ; i++ ) edg[i].clear();
    
    
    for(auto x : vec) {
        
        ll wt = x.uu;
        ll u = x.vv.uu;
        ll v = x.vv.vv;
        
        ll parU = boss(u);
        ll parV = boss(v);
        if(parU != parV) {
            par[parU] = parV;
            edg[u].push_back({wt , v});
            edg[v].push_back({wt , u});
        }
    }
    
    memset(ptable, -1 , sizeof ptable);
    dfs(1 , -1 , 0);
    
    for(int j =1 ; (1<<j)<=n ; j++ ) {
        for(int i =1 ; i <=n ; i++ ) {
            if(ptable[i][j-1] != -1) {
                ptable[i][j] = ptable[ ptable[i][j-1] ][j-1];
                wtable[i][j] = max(wtable[i][j-1] , wtable[ ptable[i][j-1] ][j-1] );
            }
        }
    }
    
    while(q--) {
        
        int u , v;
        cin>>u>>v;
        cout<<query(u , v)<<'\n';
    }
    return 0;
    
}