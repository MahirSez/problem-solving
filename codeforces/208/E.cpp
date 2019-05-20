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
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

int n ,table[20][MAX] , sz[MAX], lvl[MAX] , rec[MAX] , ans[MAX];
vector<int>edg[MAX] , *vec[MAX] ;
vector<pii> str[MAX];

void dfs1(int node ,int lev){
    
    sz[node] =1;
    lvl[node] = lev;
    for(auto x : edg[node]) {
        dfs1(x , lev+1);
        sz[node] += sz[x];
    }
}

void build() {
    
    for(int i = 1 ; (1<<i) <=n ; i++ ) {
        
        for(int j = 1 ; j <=n ; j++ ) {
            
            if( table[i-1][j] != -1) table[i][j] = table[i-1] [ table[i-1][j] ];
        }
    }
}

int getKth(int node , int k) {
    
    for(int i = 20 ; i >= 0 ; i-- ) {
        
        if( k >= (1<<i) && table[i][node] != -1 ) {
            node = table[i][node];
            k-=(1<<i);
        }
    }
    if( k ) return 0;
    return node;
}

void dfs2(int node , int keep) {
    
    int bigChild = -1;
    
    for(auto x : edg[node]) {
        if( bigChild == -1 || sz[x] > sz[bigChild]) bigChild = x;
    }
    
    for(auto x : edg[node]) {
        if( x == bigChild) continue;
        dfs2(x , 0);
    }
    
    if( bigChild == -1) vec[node] = new vector<int>();
    else {
        dfs2(bigChild , 1);
        vec[node] = vec[bigChild];
    }
    vec[node]->push_back(node);
    rec[lvl[node]]++;
    
    for(auto x : edg[node]) {
        if( x == bigChild) continue;
        
        for(auto xx : *vec[x]) {
            
            vec[node]->push_back(xx);
            rec[lvl[xx]]++;
        }
    }
    
    for(auto x : str[node]) {
        
        int h = x.uu;
        int id = x.vv;
        
        if( node == 0 ) ans[id] = 0;
        else {
            ans[id] = rec[h] -1;
        }
    }
    if( keep == 0) {
        for(auto x : *vec[node]) {
            rec[lvl[x]]--;
        }
    }
}


int main()
{
    fastRead;
    cin>>n;
    memset(table , -1  , sizeof table);
    for(int i =1 ; i<= n ; i++ ) {
        
        int par;
        cin>>par;
        table[0][i] = par;
        edg[par].push_back(i);
    }
    
    dfs1(0, 1);
    
    build();
    
    int m;
    cin>>m;
    for(int i = 1 ; i <= m ; i++ ) {
        
        int v , k;
        cin>>v>>k;
        int pp = getKth(v , k);
        str[pp].push_back({lvl[v] , i});
    }
    
    dfs2(0 , 1);
    for(int i =1 ; i<= m ; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}