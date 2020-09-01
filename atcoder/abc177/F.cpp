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
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;
int tree[4*N], lazy[4*N][3];


void push(int node, int l , int r) {

	if(lazy[node][0]) {
		tree[node] = lazy[node][2] + l - lazy[node][1];
		if(l != r) {
			for(int i =0 ; i <= 2 ; i++ ) {
				lazy[node<<1][i] = lazy[node][i];
				lazy[node<<1|1][i] = lazy[node][i];
			}
			lazy[node][0] =0;
		}
	}
}

int query(int node , int l , int r , int key ) {
	push(node , l , r);
	if( l > r || l > key || r < key ) return INF;
	if( l == r ) return tree[node];
	int mid = (l+r)/2;
	int q1 = query(node<<1 , l , mid , key);
	int q2 = query(node<<1|1 , mid+1 , r , key);
	return  min(q1 , q2);
}

void update(int node, int l , int r , int frm , int to, int Lid , int Lval) {
	push(node , l , r);
	if(l > r || l > to ||  r < frm) return;
	if(l >= frm && r <= to) {
		lazy[node][0] = 1;
		lazy[node][1] = Lid;
		lazy[node][2] = Lval;
		push(node, l , r);
		return;
	}
	int mid = (l+r)/2;
	update(node<<1 , l , mid , frm , to  , Lid , Lval);
	update(node<<1|1 , mid+1 , r , frm , to , Lid , Lval);
	tree[node] = min(tree[node<<1]  , tree[node<<1|1]);
}

int main()  {
	fastio;

	int h , w;
	cin>>h>>w;


	for(int i = 1 ; i <= h ; i++ ) {
		
		int frm ,to;
		cin>>frm>>to;
		int Lval = query(1 ,1 , w , frm-1 );
		if(frm == 1) Lval = INF;
		update(1 , 1 , w , frm , to , frm-1 , Lval);
		int ret = tree[1] + i;
		if(ret >= INF) ret = -1;
		cout<<ret<<'\n';
	}
    return 0;
    
}