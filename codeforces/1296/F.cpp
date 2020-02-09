#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pip         pair<int,pii>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

int n , m;
vector<int>edg[MAX];
vector<pip>rec;

int val[6000][6000] ;
pii edgid[6000];
int mark[6000];

bool comp(pip &p1 , pip &p2) {
    
    if(p1.uu == p2.uu) return 1;
    
    return p1.uu < p2.uu;
}

int dfs(int node , int p , int tgt) {


    
    if(node == tgt) {
        mark[tgt] = 1;
        return INF;
    }
    
    for(auto x : edg[node]) {
        if(x == p ) continue;
        
        int ret = dfs(x , node , tgt);
        if(mark[x] ) {
            
            mark[node] = 1;
            return min(ret , val[node][x] );
        }
    }
    return INF;
}

void update(int node , int p , int tgt , int wt) {
    
    if(node == tgt) return;
    
    for(auto x : edg[node]) {
        if(x == p) continue;
        
        if(mark[x] ) {
            
            if(val[node][x] ==0 ) {
                
                val[node][x] = wt;
                val[x][node] = wt;
            }
            update(x , node , tgt , wt);
        }
    }
    
    
}



bool solve(pip &x) {

    
    memset(mark , 0 , sizeof mark);
    int wt = x.uu;
    int frm = x.vv.uu;
    int to = x.vv.vv;
    
    int get = dfs(frm , -1 , to );
//    cout<<wt<<" "<<get<<'\n';
    
    if(get > wt) return 0;
    
    
    update(frm , -1 , to , wt);
    return 1;
    
    
}

int main()
{
    fastRead;
    
    cin>>n;
    for(int i =1 ; i < n ; i++ ) {
        int u , v;
        cin>>u>>v;
        edgid[i]= {u , v};
        
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    cin>>m;
    while(m--) {
        int u , v , w;
        cin>>u>>v>>w;
        rec.push_back( { w , {u , v} });
    }
    
    sort(rec.rbegin() , rec.rend());
    
    bool ok = 1;
    for(auto x : rec) {
        
        ok &= solve(x);
        
        
    }
    
    if(!ok) cout<<-1<<'\n';
    else {
        for(int i = 1 ; i < n ; i++ ) {
            int u = edgid[i].uu;
            int v = edgid[i].vv;
            cout<<max(1 , val[u][v])<<" ";
        }
        cout<<'\n';
    }
    
    return 0;
}