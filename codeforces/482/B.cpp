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
int n ,l[MAX] , r[MAX] ,q[MAX];
int tree[MAX*4] , lazy[MAX*4];
int m;

void push(int node , int l , int r) {
    if( lazy[node]) {
        tree[node] |=lazy[node];
        if( l != r) {
            lazy[node<<1] |= lazy[node];
            lazy[node<<1|1] |= lazy[node];
        }
    }
    lazy[node] = 0;
}


void update(int node ,int l , int r , int frm , int to , int val) {
    push(node , l , r);
    if( l > to || r<frm || l > r) return ;
    if( l>=frm && r <=to ) {
        lazy[node] |= val;
        push(node, l , r);
        return;
    }
    int mid = (l+r)/2;
    update(node<<1 , l , mid , frm , to , val);
    update(node<<1|1 , mid+1 , r , frm , to , val);
    tree[node] = tree[node<<1] & tree[node<<1|1];
}

int query(int node , int l , int r , int frm , int to) {
    push(node , l , r);
    if( l > r || l >to || r < frm) return ((1<<30)-1);
    if( l >=frm && r <= to ) {
        return tree[node];
    }
    int mid = (l+r)/2;
    int q1 = query(node<<1 , l , mid , frm , to);
    int q2 = query(node<<1|1 , mid+1 , r , frm , to);
    return (q1 & q2);
}

int main()
{
    fastRead;
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++ ) {
        cin>>l[i]>>r[i]>>q[i];
        l[i]--;
        r[i]--;
        update(1 , 0 , n-1 , l[i] , r[i] , q[i]);
    }
    for(int i =0 ; i < m ; i++ ) {
        int tmp = query(1, 0 , n-1 , l[i] , r[i] );
//        cout<<l[i]<<" "<<r[i]<<" ------"<< tmp<<" "<<q[i]<<endl;
        if( tmp != q[i] ) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i =0 ; i < n ; i++ ) {
        cout<<query(1 ,0 , n -1 ,i , i)<<" ";
    }
    cout<<endl;
    return 0;
}
