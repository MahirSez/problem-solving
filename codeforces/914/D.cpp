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
int n ,ara[MAX] ,tree[MAX*4],q;

void update(int node ,int l ,int r ,int key, int val) {
    if( l > r || l > key || r< key) return ;
    if( l == r) {
        tree[node] = val;
        return;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , key , val);
    update(node<<1|1 , mid+1 , r , key , val);
    tree[node] = __gcd(tree[node<<1] , tree[node<<1|1]);
}

void build(int node, int l , int r ) {
    if( l > r) return;
    if( l ==r ) {
        tree[node] = ara[l];
        return;
    }
    int mid = (l + r) >>1;
    build( node<<1 , l , mid);
    build(node<<1|1 , mid+1 , r);
    tree[node] = __gcd(tree[node<<1] , tree[node<<1|1]);
}

int query(int node ,int  l , int r , int frm ,int to ,int val) {

    if( l> r || l > to || r < frm ) {
        return 0;
    }
    if( l >= frm && r <= to ) {
        if(tree[node]%val == 0)
            return 0;
        if( l == r) return 1;
        if( tree[node<<1]%val && tree[node<<1|1]%val )
            return 2;
    }
    int mid = (l + r)>>1;
    int q1 = query(node<<1 , l , mid , frm , to , val);
    int q2 = query(node<<1|1 , mid+1 , r , frm , to , val);
    return q1 + q2;
}


int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i <= n ;i++ ) cin>>ara[i];
    cin>>q;
    build(1 , 1 , n );

    while( q-- ) {
        int tmp;
        cin>>tmp;
        if( tmp == 1 ) {
            int l , r , key;
            cin>>l>>r>>key;

            int ans = query(1 , 1 , n , l , r , key);
            if( ans <= 1 ) {
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else {
            int key, val;
            cin>>key>>val;
            update(1, 1 , n, key , val);
        }
    }
    return 0;
}
