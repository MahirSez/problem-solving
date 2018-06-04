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
int n , m ;
struct info{
    int four , sev , foursev, sevfour;
} tree[4*MAX] ;
int  lazy[4*MAX];
string str;


void push(int node ,int l , int r) {
    if( lazy[node]) {
        swap(tree[node].four , tree[node].sev);
        swap(tree[node].sevfour , tree[node].foursev);
        if( l != r) {
            lazy[node<<1] ^=1;
            lazy[node<<1|1] ^=1;
        }
        lazy[node] = 0;
    }
}

info Merge(info in1 , info in2) {
    info nw;
    nw.sev = in1.sev + in2.sev;
    nw.four = in1.four + in2.four;

    nw.foursev = max( in1.foursev , in2.foursev);
    if( in1.four && in2.sev ) nw.foursev = max( nw.foursev , in1.four + in2.sev);
    if( in1.four && in2.foursev )  nw.foursev = max(nw.foursev , in1.four + in2.foursev);
    if( in1.foursev && in2.sev ) nw.foursev = max(nw.foursev , in1.foursev + in2.sev);

    nw.sevfour = max( in1.sevfour , in2.sevfour);
    if( in1.sev && in2.four ) nw.sevfour = max( nw.sevfour , in1.sev + in2.four );
    if( in1.sev && in2.sevfour ) nw.sevfour = max( nw.sevfour , in1.sev + in2.sevfour );
    if( in1.sevfour && in2.four) nw.sevfour = max( nw.sevfour , in1.sevfour + in2.four);

    return nw;
}


void build(int node ,int l ,int r) {
    if( l == r ) {
        tree[node].foursev = 0;
        tree[node].sevfour = 0;
        if( str[l] == '4') {
            tree[node].four = 1;
            tree[node].sev = 0;
        }
        else {
            tree[node].sev = 1;
            tree[node].four = 0;
        }
        return;
    }
    int mid = (l+r)>>1;
    build(node<<1 , l , mid );
    build(node<<1|1 , mid +1 , r);
    tree[node] = Merge( tree[node<<1] , tree[node<<1|1] );
}

void update(int node ,int l , int r ,  int frm , int to ) {
    push(node , l , r);
    if( l >r || r < frm || l > to ) return;
    if( l>=frm && r <=to ) {
        lazy[node] ^=1;
        push(node, l , r) ;
        return ;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l ,mid , frm , to);
    update(node<<1|1 , mid+1 , r , frm , to);
    tree[node] = Merge(tree[node<<1] , tree[node<<1|1]);
}

void print() {
    for(int i =1; i <=10 ; i++ ) {
        cout<<i<<" "<<tree[i].sev<<" "<<tree[i].four<<" "<<tree[i].foursev<<" "<<tree[i].sevfour<<endl;
    }
    cout<<endl;
}

int main()
{
    fastRead;
    cin>>n>>m;
    cin>>str;
    str = "*" + str;
    build(1, 1 , n );
    //print();
    while( m-- ) {
        string tmp;
        cin>>tmp;
        if( tmp == "count") {
            cout<<max(tree[1].sev , max(tree[1].four, tree[1].foursev) )<<endl;
        }
        else  {
            int frm , to;
            cin>>frm>>to;
            update(1 , 1 , n , frm , to);
            //print();
        }
    }
    return 0;
}
