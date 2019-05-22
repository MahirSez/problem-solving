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
int n , ans[MAX] ,frmRoot[MAX] , sz[MAX] , lvl[MAX] , rec[MAX] , maskLen[(1<<23)+5];
vector<pii>edg[MAX] ;
vector<int> *vec[MAX];


void dfs1(int node, int mask , int lev) {
    
    sz[node] = 1;
    lvl[node] = lev;
    frmRoot[node]= mask;
    
    for(auto x : edg[node]) {
        dfs1(x.uu , mask^(1<<x.vv) , lev+1 );
        sz[node] += sz[x.uu];
    }
}

void dfs2(int node , int keep) {
    
    int bigChild = -1;
    for(auto x: edg[node]) {
        
        if( bigChild == -1 || sz[x.uu] > sz[bigChild] ) bigChild = x.uu;
    }
    
    for(auto x: edg[node]) {
        if( x.uu == bigChild ) continue;
        dfs2(x.uu , 0);
        ans[node] = max(ans[node] , ans[x.uu] );
    }
    
    if( bigChild == -1 ) vec[node] = new vector<int>();
    else {
        dfs2(bigChild , 1);
        ans[node] = max(ans[node] , ans[bigChild]);
        vec[node] = vec[bigChild];
    }
    
    for(int i =0 ; i < 23 ; i++ ) {
        
        ans[node] = max(ans[node] , maskLen[ frmRoot[node]^ rec[i] ] - lvl[node] );
    }
    
    vec[node]->push_back(node);
    maskLen[frmRoot[node]] = max(maskLen[frmRoot[node]] , lvl[node]);
    
    
    for(auto x: edg[node]) {
        
        if( x.uu == bigChild ) continue;
        
        for(auto xx : *vec[x.uu]) {
            
            for(int i =0 ; i < 23 ; i++ ) {
                
                ans[node] = max(ans[node] , lvl[xx] + maskLen[ frmRoot[xx]^rec[i] ]  - 2*lvl[node] );
            }
        }
        
        for(auto xx: *vec[x.uu]) {
            
            maskLen[frmRoot[xx]] = max(maskLen[frmRoot[xx]] , lvl[xx]);
            vec[node]->push_back(xx);
        }
    }
    
    
    if( keep ==0 ) {
        for(auto xx : *vec[node]) {
            maskLen[frmRoot[xx]] = -INF;
        }
    }
}


int main()
{
    fastRead;
    cin>>n;
    for(int i = 2 ; i<=n ; i++ ) {
        
        int par ;
        string ch;
        cin>>par>>ch;
        edg[par].push_back({i , ch[0]-'a'});
    }
    
    dfs1(1, 0 , 0);
    
    for(int i =1 ; i < 23 ; i++  ) {
        rec[i] = (1<<(i-1) );
    }
    
    for(int i = 0 ; i < (1<<23) ; i++ ) maskLen[i] = -INF;
    
    dfs2(1 , 1);
    
    for(int i =1 ; i <=n ; i++ ) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}