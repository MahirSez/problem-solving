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
int n  , lvl[MAX] ,  dist , sz[MAX] ,p[MAX] ,lf[MAX];
vector<int>edg[MAX];

void dfs1(int node , int par , int lev) {
    
    lvl[node] = lev;
    p[node] = par;
    sz[node] = 1;
    for(auto x : edg[node]) {
        if( x == par) continue;
        dfs1(x , node , lev+1);
        sz[node] += sz[x];
    }
}

int dfs2(int node ) {
    
    int big = -1;
    for(auto x : edg[node]) {
        if( x == p[node]) continue;
        if( big ==-1 || sz[x] > sz[big]) big = x;
    }
    
    if( big== -1) lf[node] = node;
    else {
        dfs2(big);
        lf[node] = lf[big];
    }
    
    for(auto x : edg[node]) {
        if( x == p[node] || x == big ) continue;
        dfs2(x);
    }
}

int dfs3(int node , int dst) {

    if( dst ==0 ) return node;
    
    int big = -1;
    for(auto x : edg[node]) {
        if( x == p[node]) continue;
        if( big ==-1 || sz[x] > sz[big]) big = x;
    }
    
    return dfs3(big , dst -1);
    
    
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i < n; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    memset(lf , -1 ,sizeof lf);
    dfs1(1 , -1 , 0);
    dfs2(1);
    
    
    int now = 1;
    
    cout<<"d "<<now<<endl;
    int dst_now_x ;
    cin>>dst_now_x;
    if( dst_now_x ==-1) {
        return 0;
    }
    
    if( dst_now_x ==0 ) {
        cout<<"! "<<now<<endl;
        return 0;
    }
    
    
    while(1) {
        

        int leaf = lf[now];
        
        cout<<"d "<<leaf<<endl;
        int dst_leaf_x;
        cin>>dst_leaf_x;
        if( dst_leaf_x ==-1) {
            return 0;
        }
        
        if( dst_leaf_x ==0 ) {
            cout<<"! "<<leaf<<endl;
            return 0;
        }
        
        int dst_now_leaf = lvl[leaf] - lvl[now];
        int dst_x_y = (dst_now_x + dst_leaf_x - dst_now_leaf )/2;
        
        
        int dst_now_y = dst_now_x - dst_x_y;
        
        now = dfs3(now , dst_now_y);
        
        if( dst_x_y ==0 ) {
            cout<<"! "<<now<<endl;
            return 0;
        }
        
        cout<<"s "<<now<<endl;
        cin>>now;
        if( now == -1 ) {
            return 0;
        }
        
        dst_now_x = dst_now_x - dst_now_y - 1;
        
        if( dst_now_x ==0 ) {
            cout<<"! "<<now<<endl;
            return 0;
        }
        
    }
    
    
}

