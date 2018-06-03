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
int n , ara[MAX] ;

int gcd(int a, int b) {
    if( b==0) return a;
    return gcd(b , a%b);
}

struct info{
    int gcd , tot;
    info(int x) {
        gcd = 0;
        tot = 0;
    }
    info() {}
} tree[4*MAX];


info Merge(info in1 , info in2) {
    info nw;
    int tmp = gcd(in1.gcd , in2.gcd);
    nw.gcd = tmp;
    nw.tot = 0;
    if( tmp == in1.gcd ) nw.tot += in1.tot;
    if( tmp == in2.gcd ) nw.tot += in2.tot;
    return nw;
}

void build(int node, int l , int r) {
    if(l == r) {
        tree[node].gcd = ara[l];
        tree[node].tot = 1 ;
        return;
    }
    int mid = (l + r)>>1;
    build( node<<1 , l , mid );
    build(node<<1|1 , mid+1 , r);
    tree[node] = Merge(tree[node<<1]  ,tree[node<<1|1]);
}

info query(int node ,int l , int r, int frm , int to ) {
    if( l > r || l > to || r < frm) return info(-1);
    if( l >=frm && r <=to ) {
        return tree[node];
    }
    int mid = (l+r)>>1;
    info q1 = query(node<<1 , l , mid , frm , to);
    info q2 = query(node<<1|1 ,mid+1 , r, frm ,to );
    return Merge(q1, q2);
}

int main()
{
    fastRead;
    cin>>n;
    for(int i = 1 ;i<=n ; i++ ) cin>>ara[i];
    build( 1, 1 , n);
    int q;
    cin>>q;
    while( q-- ) {
        int frm , to;
        cin>>frm>>to;
        info ans = query(1 , 1 , n , frm , to);
        cout<<(to-frm+1 - ans.tot)<<endl;
    }
    return 0;
}
