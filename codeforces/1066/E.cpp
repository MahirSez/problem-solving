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
#define MOD     	998244353
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll tree[4*MAX] , lazy[4*MAX] ;
int n , m ;
string s1 , s2;
ll bigMod(ll a , ll b) {

    ll p ;
    if( b == 0) return 1;
    p = ( bigMod(a , b/2) % MOD );
    p = ( p * p) % MOD;
    if( b & 1 ) p = ( p * a) % MOD;
    return p;
}
void push(int node , int l , int r) {
    tree[node] += lazy[node];
    if( l != r) {
        lazy[node<<1] += lazy[node];
        lazy[node<<1|1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node , int l , int r , int frm ,int to) {

    push(node , l , r);
    if( l >r || l > to || r < frm) return ;
    if( l >=frm && r<= to) {
        lazy[node]++;
        push(node , l , r);
        return ;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , frm , to);
    update(node<<1|1 , mid+1 , r , frm , to);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

ll query(int node ,int l ,int r , int key) {
    push(node , l , r);

    if( l > r || l > key || r < key) return 0;
    if( l == r ) {
        return tree[node];
    }
    int mid = (l+r)>>1;
    ll q1 = query(node<<1 , l ,  mid , key);
    ll q2 = query(node<<1|1 , mid+1 , r , key);
    return q1 + q2;
}

int main()
{
    cin>>n>>m;
    cin>>s1>>s2;
    reverse(s1.begin() , s1.end());
    reverse(s2.begin() , s2.end() ) ;
    for(int i =0 ; i < m ; i++ ) {
        if( s2[i]=='1'){
            update(1 ,0 , n-1 , 0 , min(n-1 , i) );
        }
    }

//    for(int i =0 ; i < n ; i++ ) {
//        cout<<i<<" "<<query(1 , 0 , n-1 , i)<<endl;
//    }
//    cout<<"done"<<endl;
    ll ans =0;
    for(int i =0 ; i < n ; i++ ) {
        if( s1[i] == '1') {
            ll tmp = ( bigMod(2 , i ) * query(1 , 0 , n-1 , i) ) %MOD;
//            cout<<i<<" "<<tmp<<endl;
            ans = (ans + tmp) %MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}

