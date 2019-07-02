#include<bits/stdc++.h>
#define MAX 300005
#define INF 1e9
using namespace std;
int t , n , a[MAX] , b[MAX] , tree[4*MAX];
queue<int>rec[MAX];


void build(int node,  int l , int r) {
    if(l == r) {
        tree[node] = a[l];
        return ;
    }
    int mid = (l+r)>>1;
    build(node<<1 , l , mid);
    build(node<<1|1 , mid+1 , r);
    tree[node] = min(tree[node<<1] , tree[node<<1|1]);
}


int query(int node , int l , int r , int frm , int to ) {

    if( l > r || l >to || r < frm ) return INF;
    if( l>=frm && r<= to ) {
        return tree[node];
    }
    int mid = (l+r)>>1;
    int q1 = query(node<<1 , l , mid , frm ,to);
    int q2 = query(node<<1|1 ,  mid+1 , r,  frm ,to);
    return min(q1 , q2);
}

void update(int node , int l , int r , int key , int val) {
    
    if(  l > r || l > key || r < key ) return;
    
    if( l == r ) {
        tree[node] = val;
        return;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , key , val);
    update(node<<1|1 , mid+1 , r , key , val);
    tree[node] = min(tree[node<<1] , tree[node<<1|1]);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>t;
    while( t-- ) {
        
        cin>>n;
        for(int i =1 ; i <= n ; i++ ) cin>>a[i];
        for(int i =1 ; i <= n ; i++ ) cin>>b[i];
        
        for(int i = 0 ; i <= n ; i++ ) {
            while(!rec[i].empty()) rec[i].pop();
        }
        
        for(int i = 1 ; i <= n; i++ ) {
            rec[a[i]].push(i);
        }
        
        build(1 , 1 , n);
        
        bool ok = true;
        
        for(int i = 1 ; i <= n ; i++ ) {
            
            int val = b[i];
            if(rec[val].empty() ) {
                ok = false;
                break;
            }
            int id = rec[val].front();
            rec[val].pop();
            
            int mnVal = query(1 , 1 , n , 1 , id);
            
            if(mnVal != b[i]) {
                ok = false;
                break;
            }
            
            update(1 , 1  ,n , id , INF);
        }
        if( ok) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    return 0;
}