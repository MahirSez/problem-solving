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

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace std;
int n , m;
vector<int>edg[MAX] , *vec[MAX] ;
vector<pii>str[MAX];
int col[MAX] ,sz[MAX] , ans[MAX]  , ase[MAX] , fre[MAX];

typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


ordered_set ost;


void dfs1(int node , int par) {
    
    sz[node] = 1;
    for(auto x : edg[node]) {
        if( x == par) continue;
        dfs1(x , node);
        sz[node] += sz[x];
    }
}

void print() {

    
    for(auto x : ost) {
        cout<<"  "<<x.uu<<" "<<x.vv<<endl;
    }
}


void dfs2(int node , int par , int keep) {

    int big = -1;
    
    for(auto x : edg[node]) {
        if( x == par) continue;
        if( big == -1 || sz[x] > sz[big]) big = x;
    }
    
    for(auto x: edg[node]) {
        if( x == par || x == big) continue;
        dfs2(x , node , 0);
    }
    
    if(big == -1) vec[node] = new vector<int>();
    else {
        dfs2(big , node , 1);
        vec[node] = vec[big];
    }
    

    vec[node]->push_back(node);
    
    ost.erase( {fre[col[node] ], col[node]} ) ;
    fre[col[node]]++;
    ost.insert({fre[col[node] ], col[node]});
    
    for(auto x : edg[node]) {
        
        if( x == big || x == par) continue;
        
        for(auto xx : *vec[x]) {
            
            vec[node]->push_back(xx);
            ost.erase({fre[col[xx] ], col[xx]});
            fre[col[xx]]++;
            ost.insert({fre[col[xx] ], col[xx]});
        }
    }

    
    
    for(auto x: str[node]) {
        
        int cnt = x.uu;
        int k = x.vv;

        int id = ost.order_of_key({cnt-1,INF});
        ans[k]  = ost.size() - id;
    }
    
    if( keep ==0) {
        
        for(auto x : *vec[node]) {
                
            ost.erase({fre[col[x] ], col[x]});
            fre[col[x]]--;
            ost.insert({fre[col[x] ], col[x]});
        }
        
    }
    

}



int main()
{
    scanf("%d %d",&n,&m);
    for(int i =1 ; i<= n ; i++ ) scanf("%d",&col[i]) , ase[col[i]] = 1;
    
    for(int i =1 ; i< MAX ; i++ ) {
        if( ase[i]) ost.insert({0,i});
    }
//    print();
    
    for(int i =1 ; i < n ; i++ ) {
        int u , v;
        scanf("%d %d",&u,&v);
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    dfs1(1 , -1);
    
    for(int i =1 ; i<= m ;i++ ) {
        
        int v , k;
        scanf("%d %d",&v , &k);
        str[v].push_back({k,i});
    }
    
    dfs2(1 , -1  , 1);
    
    for(int i =1 ; i<= m ; i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
    
}