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
int n , m , a[MAX] , b[MAX] , x , y , k;
ll tree[4*MAX] , lazy[4*MAX];

void push(int node ,int l , int r) {
    if( lazy[node] !=INF) {
        tree[node] = lazy[node];
        if( l != r) {
            lazy[node<<1] = lazy[node];
            lazy[node<<1|1] = lazy[node];
        }
        lazy[node] = INF;
    }
}
void print() {
    for(int i =1 ; i<= 10 ; i++ ) {
        if( tree[i] == INF) cout<<-123<<" ";
        else cout<<tree[i]<<" ";
    }
    cout<<endl;
}
void update(int node ,int l , int r  , int frm , int to , int val) {

    push(node, l , r);
    if( l > r || l >to || r< frm) return;
    if( l>=frm && r <= to ) {
//        cout<<node<<" "<<l<<" "<<r<<" "<<frm<<" "<<to<<" "<<val<<endl;
        lazy[node] = val;
        push(node, l , r);
        return;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , frm , to , val);
    update(node<<1|1 , mid+1 , r , frm , to , val);
}

ll query(int node ,int l , int r, int key) {
    push(node , l , r );
    if( l == r)  {
//        cout<<node<<" "<<l<<" "<<r<<" "<<key<<endl;
        return tree[node];
    }
    int mid = (l+r)>>1;
    if(key <= mid) return query(node<<1 , l , mid , key);
    return query(node<<1|1 , mid+1 , r , key);
}

int main()
{
    fastRead;
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++ ) cin>>a[i];
    for(int i = 1 ; i <= n ; i++ ) cin>>b[i];
    for(int i = 1; i<= 4*n; i++ ) tree[i] = INF;
    for(int i = 1; i<= 4*n; i++ ) lazy[i] = INF;
    while( m-- ) {
        int tmp;
        cin>>tmp;
        if( tmp == 2 ) {
            int key;
            cin>>key;
            ll ans = query(1 , 1 ,  n , key);
            if( ans == INF) cout<<b[key]<<endl;
            else cout<<a[key+ans]<<endl;
        }
        else {
            int x , y , tot;
            cin>>x>>y>>tot;
            update(1 ,1 , n , y , y + tot-1 , (x-y) );
        }
    }
    return 0;
}
