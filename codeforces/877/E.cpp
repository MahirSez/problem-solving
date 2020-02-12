#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int n, _time , col[MAX] , st[MAX] , fn[MAX] ;
int id[MAX] , tree[4*MAX] , lazy[4*MAX];

vector<int>edg[MAX];

void dfs(int node) {

    st[node] = ++_time;
    id[_time] = node;
    for(auto x : edg[node]) dfs(x);
    fn[node] = _time;
}

void build(int node , int l , int r) {
    
    if(l == r) {
        tree[node] = col[ id[l] ];
        return;
    }
    
    int mid = (l+r)/2;
    build(node<<1 , l , mid);
    build(node<<1|1 , mid+1 , r);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

void push(int node , int l , int r) {

    
    if(lazy[node]) {
        
        tree[node] = r-l+1 - tree[node];
        if(l != r) {
            lazy[node<<1] ^=1;;
            lazy[node<<1|1] ^=1;
        }
    }
    lazy[node] = 0;
}

void update(int node , int l , int r , int frm , int to ) {

    push(node , l ,r);
    
    if(l > r || l > to || r < frm ) return;
    
    if( l>=frm && r <= to) {
        
        lazy[node] ^=1;
        push(node , l , r);
        return ;
    }
    
    int mid = (l+r)/2;
    update(node<<1 , l , mid , frm , to);
    update(node<<1|1 , mid+1 , r , frm ,to);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

int query(int node , int l , int r, int frm , int to) {

    push(node , l , r);
    if(l > r || l > to || r< frm) return 0;
    
    if(l >=frm && r <=to ) return tree[node];
    
    int mid = (l+r)/2;
    int q1 = query(node<<1 , l , mid, frm , to);
    int q2 = query(node<<1|1 , mid+1 , r , frm ,to);
    return q1 + q2;
}


int main()
{
    fastRead;
    
    cin>>n;
    for(int i =2; i <= n ; i++ ) {
        int tmp;
        cin>>tmp;
        edg[tmp].push_back(i);
    }
    
    for(int i =1 ; i <=n ; i++ ) cin>>col[i];
    
    dfs(1);
    assert(_time == n);
    
    build(1 , 1 , n);
    
    int q;
    cin>>q;
    while(q--) {
        
        string str;
        int tmp;
        cin>>str>>tmp;
        if(str == "get") {
            
            int frm = st[tmp];
            int to = fn[tmp];
            
            cout<<query(1 , 1 , n , frm , to)<<'\n';
        }
        else {
            
            int frm = st[tmp];
            int to = fn[tmp];
            update(1 , 1 , n , frm ,to);
        }
    }
    return  0;
    
} 