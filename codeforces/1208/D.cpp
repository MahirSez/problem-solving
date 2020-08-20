#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int N = 2e5 + 6;
int n;
ll ara[N]  , lazy[4*N] , ans[N];
pll tree[4*N];

void build(int node ,int l , int r) {
    if(l == r) {
        tree[node].uu = ara[l];
        tree[node].vv = -l;
        return ;
    }
    int mid = (l+r)/2;
    build(node<<1 , l , mid);
    build(node<<1|1 , mid+1 , r);
    tree[node] = min(tree[node<<1] , tree[node<<1|1]);
}

void push(int node, int l , int r) {
    if(lazy[node]) {
        tree[node].uu += lazy[node];
        if(l != r) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int l , int r , int frm , int to , ll val) {
    push(node, l , r);
    if(l > r || l > to || r < frm) return;
    if( l >= frm & r <= to ) {
        lazy[node] +=val;
        push(node, l , r);
        return;
    }
    int mid = (l+r)/2;
    update(node<<1 , l , mid , frm , to , val);
    update(node<<1|1 , mid+ 1, r , frm , to, val);
    tree[node] = min(tree[node<<1] , tree[node<<1|1]);
}

void print(int node , int l, int r) {
    

    cout<<l<<" "<<r<<" ->"<<tree[node].uu<<" "<<tree[node].vv<<'\n';
    if(l >= r) return ;
    int mid= (l+r)/2;
    print(node<<1, l , mid);
    print(node<<1|1 , mid+1 , r);

}
int main()
{
    int n;
    cin>>n;
    for(int i = 1 ; i <=n ; i++ ) cin>>ara[i];

    

    build(1 , 1 , n);
    // print(1 ,1 , n);

    for(int i =1 ; i <=n ; i++ ) {
        int id = -tree[1].vv;

        ans[id] = i;

        update(1 , 1 , n , id+1 , n , -i);
        update(1 , 1 , n , id , id , INF);
    }

    for(int i =1; i <=n ; i ++ ) cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
    
}
