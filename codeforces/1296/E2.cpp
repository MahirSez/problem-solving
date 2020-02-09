#include <bits/stdc++.h>
#define MAX     	1000006
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ,q;
int ara[MAX] , tree[4*MAX] ;


void build(int node ,int l ,int r ) {
    if( l == r) {
        tree[node] = ara[l];
        return;
    }
    int mid = (l+r)>>1;
    build( node<<1 , l , mid);
    build(node<<1|1 , mid + 1 , r);
    tree[node] = max( tree[node<<1] , tree[node<<1|1]);
}

void print() {
    for(int i =1; i<=4*n ; i++ ) cout<<tree[i]<<" ";
    cout<<endl;
}

void update(int node ,int l, int r, int frm, int to ,int val) {
    if( l > r || l > to || r < frm ) return ;
    if( l >=frm && r <= to) {
        tree[node] = val;
        return ;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , frm , to , val);
    update(node<<1|1 , mid+1 , r , frm ,to , val);
    tree[node] = max( tree[node<<1] , tree[node<<1|1] );
}

int query(int node, int l , int r ,int frm ,int to ) {
    if( l > r || l > to || r < frm ) return 0;
    if( l >= frm && r <= to ) {
        return tree[node] ;
    }
    int mid = (l+r)>>1;
    int q1 = query(node<<1 , l , mid , frm ,to);
    int q2 = query(node<<1|1 , mid+1 , r , frm , to);
    return max(q1,q2);
}

vector<int>rec[30];

int main()
{
    fastRead;
    cin>>n;
    string str;
    cin>>str;
    for(int i =0 ; i < n ; i++ ) {
        rec[str[i]-'a'].push_back(i+1);
    }
    
    for(int i =0 ; i < 30 ; i++ ) reverse(rec[i].begin() , rec[i].end());
    
    for(int i= 27 ; i >=0 ; i-- ) {
        
        for(auto x : rec[i]) {
            
            int get = query(1 , 1 , n , 1 , x);
            update(1 , 1 , n , x , x ,  get+1);
        }
    }
    
    int get = query(1 ,1 , n , 1 , n );
    cout<<get<<'\n';
    for(int i =1 ; i <= n ; i++ ) cout<<query(1 , 1 , n , i , i )<<" ";
    cout<<'\n';
    
}
