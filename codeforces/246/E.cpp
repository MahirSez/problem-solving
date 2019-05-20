#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , lvl[MAX] , sz[MAX] , ans[MAX];
set<string>st[MAX];
string name[MAX];
vector<int>edg[MAX] , *vec[MAX];
vector<pii>  str[MAX];

void dfs1(int node , int lev) {
    
    lvl[node] = lev;
    sz[node] =1;
    
    for(auto x : edg[node]) {
        dfs1(x , lev+1);
        sz[node] += sz[x];
    }
}

void dfs2(int node , int keep) {

    int big = -1;
    for(auto x : edg[node])  {
        if(big == -1 || sz[x] > sz[big]) big = x;
    }
    
    for(auto x : edg[node]) {
        if( x == big) continue;
        dfs2(x , 0 );
    }
    if( big == -1) vec[node] = new vector<int>();
    else {
        dfs2(big , 1);
        vec[node] = vec[big];
    }
    
    vec[node]->push_back(node);
    st[lvl[node]].insert(name[node]);
    
    for(auto x : edg[node]) {
        if( x == big) continue;
        
        for(auto xx :*vec[x]) {
            
            st[lvl[xx]].insert(name[xx]);
            vec[node]->push_back(xx);
        }
    }
    
    for(auto x : str[node]) {
        
        int h = x.uu;
        int id = x.vv;
        ans[id] = st[h].size();
    }
    
    if( keep == 0 ) {
        
        for(auto x: *vec[node]) {
            st[lvl[x]].erase(name[x]);
        }
    }
    
    
}

int main()
{
    fastRead;
    cin>>n;
    
    for(int i =1 ; i <= n ; i++ ) {
        int par;
        cin>>name[i]>>par;
        edg[par].push_back(i);
    }
    
    dfs1(0 ,1);
    
    int m;
    cin>>m;
    for(int i =1 ; i <= m ; i++ ) {
        int v , h;
        cin>>v>>h;
        str[v].push_back({h + lvl[v], i});
    }
    
    dfs2(0,1);
    
    for(int i = 1 ; i<= m ; i++ ) {
        cout<<ans[i]<<'\n';
    }
    return 0;
}