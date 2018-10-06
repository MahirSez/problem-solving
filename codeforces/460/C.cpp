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
int n , m ,w;
ll ara[MAX] , tree[4*MAX] , mx , lazy[4*MAX];

void build(int node ,int l,  int r) {
    if( l == r) {
        tree[node] = ara[l];
        return;
    }
    ll mid = (l+r)>>1;
    build(node<<1 , l , mid);
    build(node<<1|1 , mid+1 , r);
}

void push(int node , int l , int r) {
    if( lazy[node]) {
        tree[node] += lazy[node];
        if( l != r) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
    }
    lazy[node] = 0;
}


ll query(int node , int l , int r , int key) {
    push(node , l , r);
    if( l ==r ) return tree[node];
    int mid = (l+r)>>1;
    if( key <= mid ) return query(node<<1 , l  , mid, key);
    return query(node<<1|1 , mid+1 , r , key);
}


void update(int node, int l , int r , int frm , int to , int val) {
    push(node , l , r);
    if( l >= frm && r <=to ) {
        lazy[node] += val;
        push(node, l , r);
        return;
    }
    if( l > to || r < frm ) return ;
    int mid = (l+r)/2;
    update(node<<1 , l , mid, frm , to , val);
    update(node<<1|1 ,mid+1 , r , frm , to , val);
}


bool ok(ll tmp) {
    memset( tree, 0 , sizeof tree);
    memset( lazy, 0 , sizeof lazy);
    build(1 , 0 , n-1);
    ll baki = m;
//    cout<<tmp<<" "<<baki<<endl;

    for(int i =0 ; i < n ; i++ ) {

        ll now = query(1 , 0 , n-1 , i);

        if( now >= tmp ) continue;

        ll tgt = tmp - now;

        if(tgt > baki ) return false;
        update(1 , 0 , n-1 , i , min(i+w-1, n-1) , tgt);
        baki -= tgt;
    }
//    cout<<"cholbe"<<endl;
    return true;
}



ll solve() {

    ll lo = 1 , hi = mx + m;
    ll ans = -1;
//    cout<<lo<<" "<<hi<<endl;
    while( lo <= hi) {
        ll mid= (lo+hi)/2;
        if( ok( mid ) ) {
            lo = mid+1;
            ans = mid;
        }
        else {
            hi = mid -1;
        }
    }

    return ans;
}


int main()
{
    fastRead;
    cin>>n>>m>>w;
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i];
        mx = max( ara[i] , mx);
    }

    cout<<solve()<<endl;
    return 0;
}
