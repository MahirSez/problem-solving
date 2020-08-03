#include <bits/stdc++.h>
#define MAX     	500005
using namespace std;
int t , tst , n , m;
int tree[4*MAX] , ara[MAX] , now[MAX], val[MAX] , ans[MAX];
vector<int>edg[MAX];

struct info {
    int uu , vv , id;
};

vector<info>range;

bool comp(info in1 , info in2) {
    if( in1.uu == in2.uu) {
        if( in1.vv == in2.vv) {
            return in1.id < in2.id;
        }
        return in1.vv < in2.vv;
    }
    return in1.uu< in2.uu;
}

void build(int node ,int l , int r) {
    if(l == r) {
        tree[node] = val[l];
        return;
    }
    int mid = (l+r)>>1;
    build(node<<1 , l , mid);
    build(node<<1|1 , mid+1 , r);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

void update(int node, int l ,int r , int key, int val) {
    if( l > r || l > key || r < key ) return;
    if( l == r) {
        tree[node] = val;
        return;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , key , val);
    update(node<<1|1 , mid+1 , r , key , val);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

int query(int node ,int l ,int r , int frm , int to ) {
    if( l > r || l > to || r < frm ) return 0;
    if(  l>= frm && r <=to ) {
        return tree[node];
    }
    int mid = (l+r)>>1;
    int q1 = query(node<<1 , l , mid , frm , to);
    int q2 = query(node<<1|1 , mid+1 , r , frm , to);
    return q1+ q2;
}


int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < n ; i++ ) {
        scanf("%d",&ara[i]);
        edg[ara[i]].push_back(i);
    }
    for(int i =0 ; i < m ; i++ ) {
        int frm , to;
        scanf("%d %d",&frm , &to);
        frm-- ;
        to--;
        info tmp;
        tmp.uu = frm;
        tmp.vv = to;
        tmp.id = i;
        range.push_back(tmp);
    }
    sort( range.begin() , range.end() ,comp);

    for(int i =0 ; i < n ; i++) {
        if( edg[ ara[i] ] [ now[ara[i]] ] == i ) {
            val[i] = 1;
        }
    }
    build( 1 ,0 , n-1);
    int prev= 0;

    for(int i =0 ; i < range.size() ; i++ ) {

        int frm = range[i].uu;
        int to = range[i].vv;

        for(int j = prev ; j < frm ; j++) {

            if(val[j] == 1) {
                update(1 ,0 , n-1 , j, 0);
                val[j] = 0;
                now[ara[j]]++;
                if( now[ara[j]] < edg[ara[j]].size() ) {
                    int id = edg[ ara[j] ][ now[ara[j]] ];
                    val[ id ] =1;
                    update( 1 , 0 , n-1 , id , 1);
                }
            }
        }
        prev = frm;
        ans[range[i].id] = query(1 , 0 , n-1 , frm , to);
    }
    for(int i =0 ; i < m ; i++ ) {
        printf("%d\n",ans[i]);
    }
    return 0;
}
