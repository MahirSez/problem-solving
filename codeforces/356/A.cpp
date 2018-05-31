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
int n , m ,ara[MAX] , tree[4*MAX] ,lazy[4 *MAX];


void pushdown(int node ,int l , int r) {
    if( tree[node]) return ;
    if( lazy[node]) {
        tree[node] = lazy[node];
        if( l != r) {
            lazy[node<<1] = lazy[node];
            lazy[node<<1|1] = lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node ,int l ,int r , int frm ,int to , int val) {
    pushdown(node,l,r);
    if( l > r || l > to || r < frm ) return;
    if( l >= frm && r <= to ) {
        if( tree[node] ) return;
        tree[node] = val;
        if( l != r) {
            lazy[node<<1] = val;
            lazy[node<<1|1] = val;
        }
        return;
    }
    int mid = (l + r)>>1;
    update(node<<1 , l , mid , frm , to  , val);
    update(node<<1|1 , mid+1 , r , frm , to , val);
}

int query(int node , int l ,int r , int key) {
    pushdown(node , l , r);
    if( l == r) {
        return tree[node];
    }
    int mid = ( l + r )/2;
    if( key <= mid) return query(node<<1 , l , mid , key);
    return query(node<<1|1 , mid+1 , r , key);

}
int main()
{
    fastRead;
    cin>>n>>m;
    while(m--) {
        int l , r , val;
        cin>>l>>r>>val;
        update(1 , 1 , n , l , val-1 , val);
        update(1 , 1 , n , val+1 , r , val);
    }
    for(int i =1 ; i <= n ; i++ ) {
        cout<<query(1 , 1 , n , i)<<" ";
    }
    cout<<endl;
    return 0;
}
