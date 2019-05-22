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
#define MAX     	500005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , par[MAX] , _time , in[MAX] , out[MAX] , id[MAX] , tree[4*MAX] , lazy[4*MAX]; 
vector<int>edg[MAX];

void dfs(int node , int p) {
    
    par[node] = p;
    in[node] = ++_time;
    
    for(auto x : edg[node]) {
        if(x == p) continue;
        dfs(x , node);
    }
    out[node] = _time;
}


void push(int node , int l , int r) {
    
    if( lazy[node] ) {
        
        tree[node] = (r-l+1);
        
        if(l != r) {
            lazy[node<<1] = lazy[node];
            lazy[node<<1|1] = lazy[node];
        }
        lazy[node] = 0;
    }
}

void updOff(int node , int l , int r , int key) {
    
    push(node , l , r);
    
    if( l > key || r < key) return ;
    
    if( l == r) {
        tree[node] = 0;
        return;
    }
    
    int mid = (l+r)>>1;
    updOff(node<<1 , l , mid , key);
    updOff(node<<1|1 , mid+1 , r , key);
    tree[node] = tree[node<<1] + tree[node<<1|1];
    
}

int query(int node , int l , int r , int frm , int to) {
    
    push(node , l , r) ;
    
    if( l > to || r < frm ) return 0;
    
    if( l >= frm & r <= to ) {
        return tree[node];
    }
    int mid = (l+r)>>1;
    int q1 = query(node<<1 , l , mid , frm ,to);
    int q2 = query(node<<1|1 , mid+1 ,r, frm , to);
    return q1 + q2;
}

void updOn(int node, int l , int r , int frm , int to) {

    push(node , l , r) ;
    
    if( l > to || r < frm) return ;
    if( l>=frm && r<=to ) {
        lazy[node] = 1;
        push(node , l , r);
        return;
    }
    
    int mid = (l+r)>>1;
    updOn(node<<1 , l , mid , frm , to);
    updOn(node<<1|1 , mid+1 , r , frm , to);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

void print() {

    for(int i = 1 ; i<= n ; i++ ) 
        cout<<i<<" --- "<<query(1 , 1,  _time , in[i] , out[i])<<endl;
    cout<<endl;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i < n ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    dfs(1, 0);
  
    int q;
    cin>>q;
    while( q-- ) {
        
        int c , v;
        cin>>c>>v;
        if( c == 1) {
                
            int ret = query(1 , 1 , _time , in[v] , out[v]);
            if( ret < out[v] - in[v] + 1) updOff(1 , 1 , _time , in[ par[v] ]);
            updOn(1 , 1  , _time , in[v] , out[v]);
        }
        else if( c== 2) {
            updOff(1 , 1 , _time , in[v]);
        }
        else {
            int ret = query(1 , 1 , _time , in[v] , out[v]);
            if( ret < out[v] - in[v] + 1) cout<<"0\n";
            else cout<<"1\n";   
        }
        
//        print();
    }
    return 0;
}