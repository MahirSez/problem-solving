#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e18
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ,q;
ll ara[MAX] , tree[4*MAX] ,lazy[4*MAX];

void pushdown(int node ,int l ,int r) {
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

void print() {
    for(int i =1; i<=4*n ; i++ ) cout<<tree[i]<<" ";
    cout<<endl;
}

void update(int node ,int l, int r, int frm, int to ,int val) {
    pushdown(node, l , r);
    if( l > r || l > to || r < frm ) return ;
    if( l >=frm && r <= to) {
        lazy[node] += val;
        pushdown(node, l , r);
        return ;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , frm , to , val);
    update(node<<1|1 , mid+1 , r , frm ,to , val);
    tree[node] = min( tree[node<<1] , tree[node<<1|1] );
}

ll query(int node, int l , int r ,int frm ,int to ) {
    pushdown(node, l , r);
    if( l > r || l > to || r < frm ) return INF;
    if( l >= frm && r <= to ) {
        return tree[node] ;
    }
    int mid = (l+r)>>1;
    ll q1 = query(node<<1 , l , mid , frm ,to);
    ll q2 = query(node<<1|1 , mid+1 , r , frm , to);
    return min(q1,q2);
}

int main() {
    fastRead;

    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    build(1 , 0 , n - 1 );

    cin>>q>>ws;

    while( q-- ) {
        int frm , to , val;
        string s;
        stringstream ss;
        getline(cin,s);
        ss<<s;
        if( ss>>frm>>to>>val) {

            if( frm <= to)
                update(1 ,0 , n-1 , frm ,to , val);
            else {
                update(1 , 0 , n-1 , frm , n-1 , val);
                update(1 , 0 , n-1 , 0 , to , val);
            }
        }
        else {
            if( frm <= to ) {
                cout<<query(1 , 0 , n-1 , frm , to)<<endl;
            }
            else {
                ll q1 = query(1, 0 , n-1 , frm , n-1 );
                ll q2 = query(1 , 0 , n-1 , 0 , to);
                cout<<min(q1 , q2)<<endl;
            }
        }
    }
    return 0;
}

