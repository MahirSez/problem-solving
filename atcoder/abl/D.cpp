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

const int nn = 300001;

int  tree[4*N] ;

int query(int node, int l , int r ,int frm ,int to ) {
    if( l > r || l > to || r < frm ) return 0;
    if( l >= frm && r <= to ) return tree[node] ;
    int mid = (l+r)>>1;
    int q1 = query(node<<1 , l , mid , frm ,to);
    int q2 = query(node<<1|1 , mid+1 , r , frm , to);
    return max(q1,q2);
}

void update(int node ,int l, int r, int frm, int to ,int val) {

    if( l > r || l > to || r < frm ) return ;
    if( l >=frm && r <= to) {
        tree[node] = max(tree[node] , val);
        return ;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , frm , to , val);
    update(node<<1|1 , mid+1 , r , frm ,to , val);
    tree[node] = max( tree[node<<1] , tree[node<<1|1] );
}
int main() {
    int n ,k;
    cin>>n>>k;

    

    while(n--) {
        int tmp;
        cin>>tmp;
        tmp++;
        int get = query(1 , 1 , nn , max(0, tmp - k) , min(tmp + k, nn) );
        update(1 ,1 , nn , tmp , tmp, get+1);
    }
    cout<<tree[1]<<'\n';
    return 0;
}