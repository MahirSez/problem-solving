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
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
ll ara[MAX] , tree[4*MAX] , lazy[4*MAX];

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


void build(int node ,int l ,int r ) {
    if( l == r) {
        tree[node] = ara[l];
        return;
    }
    int mid = (l+r)>>1;
    build( node<<1 , l , mid);
    build(node<<1|1 , mid + 1 , r);
    tree[node] = min( tree[node<<1] , tree[node<<1|1]);
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
    tree[node] = min( tree[node<<1] , tree[node<<1|1] );
}

ll query(int node, int l , int r ,int frm ,int to ) {
    push(node, l , r);
    if( l > r || l > to || r < frm ) return INF;
    if( l >= frm && r <= to ) {
        return tree[node] ;
    }
    int mid = (l+r)>>1;
    ll q1 = query(node<<1 , l , mid , frm ,to);
    ll q2 = query(node<<1|1 , mid+1 , r , frm , to);
    return min(q1,q2);
}

void print() {

    for(int i =0 ; i <= n+1 ; i++) {
        cout<<query(1 , 0 , n +1 , i , i )<<" ";
    }
    cout<<endl;
}



int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i <= n ; i++) cin>>ara[i];
    build(1 , 0 , n+1);
//    print();
    for(int i = 1 ; i <=n+1 ; i++ ) {
        update(1 , 0 , n+1 , i , n+1 , 1);
    }
    ll mx = 0;
//    print();

    for(int i = 1 ; i<= n ; i++ ) {
        update(1 , 0 , n+1 , i , n+1 , -1);
        update(1 , 0 , n+1 , 0 , i-1  , 1);
        ll q1 = query(1 , 0 , n+1 , i+1 , n+1);
        ll q2 = query(1 , 0 , n+1 , 0 , i-1 );
        mx = max(mx , min(ara[i] , min(q1 , q2) ) );
//        cout<<mx<<endl;
//        print();
    }
    cout<<mx<<endl;
    return 0;
}
