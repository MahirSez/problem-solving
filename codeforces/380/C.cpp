#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
string str;
int q , frm , to;
struct info {

    int open , closed , matched;
    info() {}
    info(int n) {
        open = closed =  matched = 0;
    }
} tree[3 * MAX];

info Merge(info in1 , info in2) {

    info nw;
    int tmp = min( in1.open , in2.closed ) ;
    nw.matched = in1.matched + in2.matched + tmp * 2;
    nw.open = in1.open + in2.open - tmp;
    nw.closed = in1.closed + in2.closed - tmp;
    return nw;
}
void build(int node ,int b , int e) {

    if( b == e) {
        if( str[b]=='(') tree[node].open = 1 , tree[node].closed = 0 , tree[node].matched = 0;
        else tree[node].closed = 1 , tree[node].open = 0  , tree[node].matched = 0;
        return;
    }

    int mid = (b+e)>>1;
    build( node<<1 , b  , mid);
    build(node<<1|1 , mid +1 ,e);
    tree[node] = Merge(tree[node<<1] , tree[node<<1|1]);
}
info query(int node ,int b , int e) {

    if( b > to || e < frm)
        return info(0);
    if( b >= frm && e <= to )
        return tree[node];

    int mid = (b+e)>>1;
    info q1 = query(node<<1,b , mid );
    info q2 = query(node<<1|1 ,mid+1,e);
    return Merge(q1 , q2);

}

void print() {

    for(int  i=1 ; i<= 30; i ++ ) {

        cout<<i<<" "<<tree[i].open<<" "<<tree[i].closed<<" "<<tree[i].matched<<endl;
    }
}
int main()
{
    fastRead;
    cin>>str>>q;
    build(1 , 0 , str.size()-1 );
    //print();
    while( q-- ) {

        cin>>frm>>to;
        frm--;
        to--;
        cout<<query(1 , 0 , str.size()-1).matched<<endl;
    }
    return 0;
}
