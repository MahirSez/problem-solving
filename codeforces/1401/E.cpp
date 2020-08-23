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

int ara[N], tree[4*N];


void update(int node, int l , int r , int id , int val) {
    if(l > r || l > id || r < id)return ;
    if(l == r) {
        tree[node] += val;
        return;
    }
    int mid = (l+r)/2;
    update(node<<1 , l ,mid , id , val);
    update(node<<1|1 , mid+1 , r , id , val);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

int query(int node,  int l , int r , int frm , int to ) {
    if( l > r || l > to || r < frm) return 0;
    if( l>=frm && r <= to) return tree[node];
    int mid = (l+r)/2;
    int q1 = query(node<<1, l , mid , frm ,to);
    int q2 = query(node<<1|1 , mid+1 ,r, frm , to);
    return q1 + q2;
}

vector<int>st[N] , en[N] ;
vector<pii> rec[N];
typedef tuple<int, int,int>tp;


int main() {
    fastio;
    int n , m ;
    cin>>n>>m;


    ll fullX = 0 , fullY = 0, cnt = 0;
    int nn = 1e6;

    for(int i =0 ; i < n ; i ++ ) {
        int y , lx , rx;
        cin>>y>>lx>>rx;
        if(lx == 0 &&  rx == nn ) fullX++;
        rec[y].push_back({lx , rx});
    }

    for(int i =0 ; i < m ; i++ ) {
        int x , ly , ry;
        cin>>x>>ly>>ry;

        if(ly == 0 &&  ry == nn ) fullY++;
        st[ly].push_back(x);
        en[ry].push_back(x);
    }
    

    for(int i =0 ; i <= nn  ; i++ ) {

        for(auto x : st[i]) update(1 , 0 , nn , x , 1);
        for(auto x : rec[i]) cnt += query(1 , 0 , nn , x.uu , x.vv );
        for(auto x : en[i]) update(1 , 0 , nn , x , -1);
    }

    // cout<<cnt<<" "<<fullX<<" "<<fullY<<'\n';

    ll ans = 1LL + fullX + fullY + cnt;
    cout<<ans<<'\n';
    return 0;
}