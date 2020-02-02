#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
ll ara[MAX] , id[MAX] , cst[MAX]  , sum[MAX];
ll tree[4*MAX] , lazy[4*MAX];

int n;

void build(int node , int l, int r) {
    
    if(l == r) {
        tree[node] = sum[l];
        return;
    }
    int mid = (l+r)/2;
    build(node<<1 , l , mid);
    build(node<<1|1 , mid+1 , r);
    tree[node] = min( tree[node<<1] , tree[node<<1|1]);
}

void push(int node, int l , int r) {
    
    if(lazy[node]) {
        
        tree[node] += lazy[node];
        
        if(l != r) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
    }
    lazy[node] = 0;
}

void update(int node , int l , int r , int frm , int to , ll val) {
    
    push(node , l , r);
    if(l > r || l > to || r < frm ) return;
    if( l >= frm && r <=to ) {
        lazy[node] += val;
        push(node , l  , r);
        return;
    }
    
    int mid = (l+r)/2;
    update(node<<1 , l , mid , frm , to , val);
    update(node<<1|1 , mid+1 , r , frm ,to , val);
    tree[node] = min(tree[node<<1] , tree[node<<1|1]);
}

ll query(int node , int  l , int r , int frm , int to) {
    
    push(node , l , r);
    if(l > r || l > to || r < frm) return INF;
    if( l >= frm && r<=to ) {
        return tree[node];
    }
    
    int mid = (l+r)/2;
    ll q1 = query(node<<1 , l , mid , frm ,to);
    ll q2 = query(node<<1|1 , mid+1 , r , frm , to );
    return min(q1 , q2);
}


int main()
{
    fastRead;
    cin>>n;
    for(int i =1;  i <=n ; i++ ) {
        cin>>ara[i];
        id[ara[i]] = i;
    }
    
    for(int i =1 ; i <=n ; i++ ) {
        cin>>cst[i];
        sum[i]  = sum[i-1] + cst[i];
    }
    
    build(1 , 1 , n );
    

    ll ans = query(1 , 1 , n , 1 , n -1);
    
    
    for(int i =1 ; i <=n ; i++ ) {
        int pos = id[i];
        update(1 , 1 , n , 1 , pos-1 , cst[pos]);
        update(1 , 1 , n , pos , n , -cst[pos] ) ;
        ll ret = query(1 , 1 , n , 1 , n -1);
        ans = min(ans , ret);
    }
    cout<<ans<<'\n';
    return  0;
}