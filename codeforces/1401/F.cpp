#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int swp[50] , rev[50], ara[N];
ll tree[4*N];

void build(int node, int l , int r) {
    if(l == r) {
        tree[node] = ara[l];
        return;
    }
    int mid = (l+r)/2;
    build(node<<1, l , mid);
    build(node<<1|1, mid+1 , r);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

void update(int node, int sz, int id , int val, int lvl)  {

    // cout<<node<<" "<<sz<<" "<<id<<" -- "<<val<<" "<<lvl<<'\n';
    if( id <= 0 || id > sz) return;

    if(sz == 1) {
        tree[node] = val;
        return;
    }
    int mid = sz/2;

    if(rev[lvl]) id = sz - id + 1;

    int l = id;
    int r = id - mid;
    if(swp[lvl]) swap(l ,r);

    update(node<<1 , sz/2 , l , val , lvl-1);
    update(node<<1|1 , sz/2 , r , val , lvl-1);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

ll query(int node, int sz, int frm , int to , int lvl) {

    if(frm > to || frm <= 0 || to <= 0 || to - frm + 1 > sz) return 0;

    if(frm == 1 && to == sz) return tree[node];

    int mid = sz/2;
    int l = frm , r = to;

    if(rev[lvl]) {
        l = sz - to + 1;
        r = sz - frm + 1;
    }

    int l1 = l;
    int r1 = min(mid , r);
    int l2 = max(l - mid , 1);
    int r2 = r - mid;


    if(swp[lvl]) {
        swap(l1 , l2);
        swap(r1 , r2);
    }

    // cout<<" --- "<<'\n';
    // cout<<node<<" "<<sz<<" "<<lvl<<'\n';
    // cout<<l<<" "<<r<<'\n';
    // cout<<l1<<" "<<r1<<'\n';
    // cout<<l2<<" "<<r2<<'\n';

    ll q1 = query(node<<1 , sz/2 , l1 , r1 , lvl-1);
    ll q2 = query(node<<1|1 , sz/2 , l2 , r2 , lvl-1);

    return q1 + q2;

}

void print(int node, int l , int r) {

    if(l == r) {
        cout<<node<<" "<<l<<" "<<r<<" -- "<<tree[node]<<'\n';
        return;
    }
    int mid = (l+r)/2;
    print(node<<1, l , mid);
    print(node<<1|1 , mid+1 , r);
}


int main() {
    fastio;
    
    int n , m;
    cin>>n>>m;
    for(int i =1 ; i <=(1<<n) ; i++ ) cin>>ara[i];
    
    build(1 , 1 , (1<<n) );
    while(m--) {
        int typ;
        cin>>typ;
        if(typ == 1) {
            int x , val;
            cin>>x>>val;
            update(1 , (1<<n) , x , val , n );
            // print(1 , 1 , (1<<n));
            // return 0;
            
        }
        else if(typ ==2 ) {
            int k;
            cin>>k;
            // for(int i = 0 ;i <= k ; i++ ) rev[i] ^=1;
            rev[k] ^=1;
            // swp[k] ^= 1;
        }
        else if(typ == 3) {
            int k;
            cin>>k;
            swp[k+1] ^= 1;
        }
        else {
            int l , r;
            cin>>l>>r;
            ll ret = query(1 , (1<<n) , l , r , n );
            cout<<ret<<'\n';
        }
        // cout<<'\n';

        // for(int i = 0 ; i <= n ; i++ ) cout<<rev[i]<<" ";
        // cout<<'\n';

        
        // for(int i = 0 ; i <= n ; i++ ) cout<<swp[i]<<" ";
        // cout<<'\n';

        // for(int i =1 ; i<=(1<<n) ; i++ ) {
        //     cout<<i<<" --> "<<query(1 ,(1<<n) , i , i , n )<<'\n';
        // }

        // cout<<"-----------\n";
    }

    return 0;
}

/*
3 1
7 0 8 8 7 1 5 2
2 1
*/