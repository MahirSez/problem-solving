#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll n , m , l , r , c , p , k , mxSz;
pii tree[4*MAX];
vector<pii>on[MAX], off[MAX];


void update(ll node ,ll l , ll r , ll key , ll tot) {
    if( l >r || l > key || r < key) return ;
    if( l == r) {
        tree[node].uu += tot;
        tree[node].vv += key*tot;
        return;
    }
    ll mid = (l+r)>>1;
    update(node<<1 , l , mid , key , tot);
    update(node<<1|1 , mid+1 , r , key , tot);
    tree[node].uu = tree[node<<1].uu + tree[node<<1|1].uu;
    tree[node].vv = tree[node<<1].vv + tree[node<<1|1].vv;
}

ll query(ll node, ll l , ll r , ll key) {

    if( l == r) {
        return min(key , tree[node].uu)*l;
    }
    ll mid = (l+r)>>1;
    if( tree[node<<1].uu < key ) {
        return tree[node<<1].vv + query(node<<1|1 , mid+1 , r , key  - tree[node<<1].uu ) ;
    }
    return query(node<<1 , l , mid , key);
}

int main()
{
    fastRead;
    cin>>n>>k>>m;
    for(int i = 0 ; i < m ; i++ ) {
        cin>>l>>r>>c>>p;
        on[l].push_back({c,p});
        off[r].push_back({c,p});
        mxSz = max(mxSz , p);
    }
    ll ans = 0;
    for(int i =1 ; i<= n ; i++ ) {

        for(int j =0 ; j < on[i].size() ; j++ ) {

            ll tot = on[i][j].uu;
            ll val = on[i][j].vv;
            update(1 , 1 , mxSz , val , tot);
        }
        ans += query(1 , 1 , mxSz , k);
        for(int j =0 ; j < off[i].size() ; j++ ) {

            ll tot = off[i][j].uu;
            ll val = off[i][j].vv;
            update(1 , 1 , mxSz , val , -tot);
        }

    }
    cout<<ans<<endl;
    return 0;
}
