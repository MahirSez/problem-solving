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
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m , tree[26][4*MAX] , lazy[26][4*MAX];
string str;

void build(int node, int l , int r) {
    if( l == r) {
        tree[(str[l]-'a')][node] = 1;
        return;
    }
    int mid = (l+r)>>1;
    build( node<<1, l , mid);
    build(node<<1|1 , mid+1 , r);
    for(int i =0 ;  i< 26; i++ ) {
        tree[i][node] = tree[i][node<<1] + tree[i][node<<1|1];
    }
}

void push(int node , int l , int r ,int i) {
    if( lazy[i][node] != -1 ) {
        tree[i][node] = (r-l+1)*lazy[i][node];
        if( l != r ) {
            lazy[i][node<<1] = lazy[i][node];
            lazy[i][node<<1|1] = lazy[i][node];
        }
        lazy[i][node] = -1;
    }
}

void update(int node ,int l , int r , int frm , int to , int val , int i) {
    push(node, l , r , i);
    if( l >r || r < frm || l > to ) return;
    if( l >=frm && r <= to ) {
        lazy[i][node] = val;
        push(node, l , r , i);
        return;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , frm , to , val , i);
    update(node<<1|1 , mid+1 ,r, frm , to , val , i);
    tree[i][node] = tree[i][node<<1] + tree[i][node<<1|1];
}

int query(int node , int l , int r , int frm , int to , int i) {
    push(node , l , r, i);
    if( l > r || l >to || r  < frm ) return 0;
    if( l>=frm && r <=to ) return tree[i][node];
    int mid = (l+r)>>1;
    int q1 = query(node<<1 , l , mid , frm, to , i);
    int q2 = query(node<<1|1 , mid+1 , r , frm , to , i);
    return q1+q2;
}

void print() {
    for(int i = 1 ; i<=26 ; i++ ) {
        cout<<i<<" "<<tree[0][i]<<"\n";
    }
}

int main()
{
	fastRead;
	cin>>n>>m;
	cin>>str;
	str = "*" + str;
	memset( lazy , -1 , sizeof lazy);
	build(1 , 1 , n);
//	print();
    while( m-- ) {
        int frm , to , up;
        cin>>frm>>to>>up;

        if( up == 1) {
            int now = frm;
            for(int i = 0 ; i <26 ; i++ ) {

                int tot = query(1 , 1 , n , frm , to , i);
                update(1 , 1 , n , frm ,to , 0 , i);
                update(1 , 1 , n , now , now + tot-1 , 1 , i);
                now+=tot;
            }
        }
        else {
            int now = frm ;
            for(int i = 25 ; i>=0 ; i--) {
                int tot = query(1 , 1 , n , frm , to , i);
                update(1 , 1 , n , frm ,to , 0 , i);
                update(1 , 1 , n , now , now + tot-1 , 1 , i);
                now+=tot;
            }
        }
    }
    string ans = "";
    for(int i = 1 ; i<= n ;i++) {
        for(int j = 0; j < 26 ; j++ ) {
            int val = query(1 , 1 , n , i , i , j);
            if( val ) ans += (char)(j + 'a');
        }
    }
    cout<<ans<<"\n";
    return 0;
}
