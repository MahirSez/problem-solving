#include<bits/stdc++.h>
#define MAX 1000006

using namespace std;
int n ,a[MAX] ,m , b[MAX], tree[4*MAX] ,lazy[4*MAX];


void push(int node, int l , int r) {

    if( lazy[node] ) {

        tree[node] += lazy[node];

        if( l != r) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node ,int  l , int r , int frm , int to , int val) {

    push(node , l , r);

    if( l > r|| l >to || r < frm) return ;

    if( l >= frm && r<= to ) {
        lazy[node] += val;
        push(node,  l , r);
        return ;
    }

    int mid = (l+r)>>1;
    update(node<<1 , l , mid , frm , to , val);
    update(node<<1|1 , mid+1 , r, frm , to , val);

    tree[node] = max(tree[node<<1] , tree[node<<1|1] );
}

int query(int node, int l , int r) {

    push(node , l , r);
    if( tree[node] <=0 ) return -1;

    if( l == r) {
        return l;
    }

    int mid = (l+r)>>1;
    push(node<<1 , l , mid);
    push(node<<1|1 , mid+1 , r);

    if( tree[node<<1|1] > 0 ) return query(node<<1|1 , mid+1 ,r);
    return query(node<<1 , l , mid);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for(int i =1 ; i <= n ; i++) {
        cin>>a[i];
        update(1 , 1 , MAX , 1 , a[i] , 1 );
    }
    for(int i = 1 ; i<= m ; i++) {
        cin>>b[i];
        update(1 , 1 , MAX , 1 , b[i] , -1);
    }

    int q;
    cin>>q;
    while(q-- ) {

        int typ , id , val;
        cin>>typ>>id>>val;

        if( typ == 1) {

            update(1 , 1 , MAX , 1 , a[id] , -1 );
            a[id] = val;
            update(1 , 1 , MAX , 1 , a[id] , 1 );
        }
        else {

            update(1 , 1 , MAX , 1 , b[id] , 1 );
            b[id] = val;
            update(1 , 1 , MAX , 1 , b[id] , -1 );
        }

        cout<<query(1 , 1 , MAX)<<'\n';
    }
    return 0;
}
