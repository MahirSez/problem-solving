#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD =  998244353;


const int N = 1e6 + 6;
ll ara[N] , tree[4*N] ,lazy[4*N], sz[4*N];
ll ten[N] , rec[15][N];

void build(int node ,int l ,int r ) {
    if( l == r) {
        tree[node] = 1;
        sz[node] = 1;
        return;
    }
    int mid = (l+r)>>1;
    build( node<<1 , l , mid);
    build(node<<1|1 , mid + 1 , r);
    
    
    int rlen = sz[node<<1|1];
    tree[node] = ( (tree[node<<1] * ten[rlen])%MOD +  tree[node<<1|1] ) %MOD;

    sz[node] = sz[node<<1] + sz[node<<1|1];

    // cout<<l<<" "<<r<<" "<<sz[node]<<'\n';
}

void pre() {
    ten[0] = 1;
    for(int i= 1; i < N ; i++ ) {
        ten[i] = (ten[i-1] * 10 ) % MOD;
        assert(ten[i] > 0);
    }

    for(int i =1 ; i <=9 ; i++ ) {
        rec[i][1] = i;

        for(int j =2 ; j < N ; j++ ) {
            rec[i][j] = ( i * ten[j-1] + rec[i][j-1]) % MOD;
            assert(rec[i][j] > 0);
            // if(j <=10) cout<<i<<" "<<rec[i][j]<<'\n';
        }
    }
}

void push(int node ,int l ,int r) {
    if( lazy[node]) {
        // cout<<l<<" "<<r<<" "<<rec[ lazy[node] ] [ sz[node] ]<<'\n';
        tree[node] = rec[ lazy[node] ] [ sz[node] ];
        if( l !=r) {
            lazy[node<<1] = lazy[node];
            lazy[node<<1|1] =lazy[node];
        }
        lazy[node] = 0;
    }
}


void update(int node ,int l, int r, int frm, int to ,int val) {
    push(node, l , r);
    if( l > r || l > to || r < frm ) return ;
    if( l >=frm && r <= to) {
        lazy[node] = val;
        push(node, l , r);
        return ;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , frm , to , val);
    update(node<<1|1 , mid+1 , r , frm ,to , val);
    int rlen = sz[node<<1|1];
    tree[node] = ( (tree[node<<1] * ten[rlen])%MOD +  tree[node<<1|1] ) %MOD;
}

int main() {
    fastio;
    pre();
    int n , k;
    cin>>n>>k;

    build(1 ,1 , n );
    
    while(k--) {
        int l , r , dig;
        cin>>l>>r>>dig;
        update(1 , 1 , n , l , r , dig);
        cout<<tree[1]<<'\n';
    }
    return 0;
}