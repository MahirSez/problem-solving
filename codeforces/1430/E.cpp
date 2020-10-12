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

const int N = 2e5 + 6;

int tree[4*N] ;
int lazy[4*N];


void push(int node,int l ,int r) {
    if(lazy[node]) {
        tree[node] += lazy[node];
        if(l != r) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

int query(int node, int l , int r , int id) {
    push(node, l , r);
    if(l > r || l > id || r < id) return 0;
    if(l == r) return tree[node];
    int mid = (l+r)/2;
    int q1 = query(node<<1, l , mid , id);
    int q2 = query(node<<1|1 , mid+1 , r , id);
    return q1 + q2;
}
void update(int node , int l , int r ,int frm , int to , int val)  {
    push(node, l ,r);
    if(l > r || l > to || r < frm) return ;
    if(l >= frm && r <= to) {
        lazy[node] += val;
        push(node, l , r);
        return ;
    }
    int mid = (l+r)/2;
    update(node<<1 , l , mid , frm, to , val);
    update(node<<1|1 , mid+1  ,r , frm, to, val);
    tree[node] = tree[node<<1]  + tree[node<<1|1];
}


queue<int>q[30];
int main() {
    fastio;
    int n;
    cin>>n;

    string s;
    cin>>s;
    for(int i =1 ; i <= n ; i++ ) {
        int flg = s[i-1]-'a' + 1;
        q[flg].push(i);
    }

    string tgt = s;
    reverse(tgt.begin() , tgt.end());
    ll ans = 0;

    for(int i =1 ; i <=n ; i++ ) {
        int flg = tgt[i-1] - 'a'+ 1;
        int id = q[flg].front();
        q[flg].pop();

        int add = query(1, 1, n, id );
        ans += add + id - i;
        update(1 , 1 , n , 1 , id, 1);
    }
    cout<<ans<<'\n';

    
    
    
    return 0;
}