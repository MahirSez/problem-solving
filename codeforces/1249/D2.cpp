
#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8

#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 2e5 + 5;
int n ,k;
int  tree[4*MAX] ,lazy[4*MAX];

struct line {
    
    int l , r , id;
};

line ara[MAX];

void push(int node ,int l ,int r) {
    if( lazy[node]) {
        tree[node] += lazy[node];
        if( l !=r) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] +=lazy[node];
        }
        lazy[node] = 0;
    }
}


void print() {
    for(int i =1; i<=4*n ; i++ ) cout<<tree[i]<<" ";
    cout<<endl;
}

void update(int node ,int l, int r, int frm, int to ,int val) {
    push(node, l , r);
    if( l > r || l > to || r < frm ) return ;
    if( l >=frm && r <= to) {
        lazy[node] += val;
        push(node, l , r);
        return ;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , frm , to , val);
    update(node<<1|1 , mid+1 , r , frm ,to , val);
    tree[node] = max( tree[node<<1] , tree[node<<1|1] );
}

int query(int node, int l , int r ,int frm ,int to ) {
    push(node, l , r);
    if( l > r || l > to || r < frm ) return 0;
    if( l >= frm && r <= to ) {
        return tree[node] ;
    }
    int mid = (l+r)>>1;
    int q1 = query(node<<1 , l , mid , frm ,to);
    int q2 = query(node<<1|1 , mid+1 , r , frm , to);
    return max(q1,q2);
}

bool comp(line p1 , line p2)  {
    return (p1.r < p2.r );
}


vector<int>tmp;
void solve() {

//    cout<<tgt<<'\n';
    tmp.clear();
    memset(tree , 0 , sizeof tree);
    memset(lazy , 0 , sizeof lazy);
    
    for(int i =0 ; i < n ; i++ ) {
        
        int frm = ara[i].l , to = ara[i].r;
        
        int val = query(1 , 1 , 2e5, frm , to );
        
//        cout<<frm<<" "<<to<<" "<<val<<'\n';
        assert(val <= k );
        if(val == k) tmp.push_back(ara[i].id);
        else update(1 , 1 , 2e5 , frm , to , 1);
    }
    
}


int main()
{
    fastRead;
    cin>>n>>k;
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i].l>>ara[i].r;
        ara[i].id = i+1;
    }
    
    sort(ara , ara  + n , comp);
    
    
    int lo = 0 , hi = n;

    
    vector<int>ans;
    
    
//    while(lo<= hi) {
//        
//       int mid = (lo+hi) /2;
//       
//        if(ok(mid)) {
//            ans = tmp;
//            hi = mid - 1;
//        }
//        else lo = mid+1;
//    }
    
    
    solve();
    ans = tmp;
    cout<<ans.size()<<'\n';
    for(auto x : ans) cout<<x<<" ";
    cout<<'\n';
    
    return 0;
}
