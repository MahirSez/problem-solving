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
ll ara[MAX] , bg[MAX] , sm[MAX] , tmp[MAX];
ll tree[4*MAX] , lazy[4*MAX];
map<ll,int>mp;
int cnt;


void push(int node, int l ,int r) {
    if( lazy[node]) {
        tree[node]+=lazy[node];
        if( l!=r) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }
}


void update(int node, int l ,int r ,int frm ,int to) {
    push(node , l ,r );
    if(l > r || r < frm || l >to || frm > to) return;
    if( l >= frm && r <= to) {
        lazy[node]++;
        push(node , l , r);
        return ;
    }
    int mid = (l + r)>>1;
    update(node<<1 , l , mid , frm , to);
    update(node<<1|1 , mid+1 , r , frm , to);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

ll query(int node, int l , int r, int key) {
    push(node, l , r );
    if( l > r || l > key || r < key) return 0;
    if( l == r) return tree[node];
    int mid = (l+r)>>1;
    ll q1 = query(node<<1 , l , mid, key);
    ll q2 = query(node<<1|1 , mid+1 , r , key);
    return q1+q2;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i <= n ; i++ ) {
        cin>>ara[i];
        tmp[i] = ara[i];
    }
    sort( tmp +1 , tmp + n + 1);
    for(int i = 1 ; i<= n ; i++ ) {
        mp[tmp[i]] = i;
    }
    for(int i = 1 ; i <= n ; i++ ) {
        ara[i] = mp[ara[i]];
    }
    for(int i =1 ; i <= n ;i++ ) {
        update(1 ,1 , n , 1 , ara[i]-1 );
        bg[i] = query(1 , 1 , n , ara[i] );
    }
    memset( tree,  0 ,sizeof tree);
    memset( lazy, 0 , sizeof lazy);
    ll ans = 0;
    for(int i = n ; i >= 1 ; i-- ) {
        update(1,  1 , n , ara[i]+ 1, n);
        sm[i] = query(1 ,1 , n , ara[i]);
        ans += bg[i] * sm[i];
    }
    cout<<ans<<endl;
    return 0;
}
