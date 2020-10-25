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
int tree[4*N];
int n;
int last[N];
vector<pii>q[N];
int ara[N];

int query(int node, int l , int r, int frm, int to) {
    if(l > r || l > to || r< frm) return INF;
    if(l >= frm && r <= to) return tree[node];
    int mid = (l+r)/2;
    int q1 = query(node<<1, l , mid ,frm , to);
    int q2 = query(node<<1|1, mid+ 1, r , frm , to);
    return min(q1, q2);
}

void update(int node, int l, int r, int key, int val) {
    if(l > r || l > key || r< key) return ;
    if(l == r) {
        tree[node] = val;
        return ;
    }
    int mid = (l+r)/2;
    update(node<<1, l , mid , key , val);
    update(node<<1|1, mid+1 , r , key , val);
    tree[node] = min(tree[node<<1] , tree[node<<1|1]);
}
int main()  {
    fastio;

    int n;
    cin>>n;

    set<int>s;

    for(int i =1 ; i <=n ; i++ ) {
        cin>>ara[i];

        if(ara[i] != 1) s.insert(1);
        int l = last[ara[i]];
        int ret = query(1 , 1 , n , 1 , ara[i]-1);

    
        // cout<<ara[i]<<" "<<l<<" "<<ret<<'\n';


        if(ara[i] != 1 && ret> l ) {
            // cout<<ara[i]<<"\n";
            s.insert(ara[i]);
        }

        last[ara[i]] = i;
        update(1, 1 , n , ara[i] , i);
    }

    for(int i =2; i <=n+1 ; i++ ) {
        int l = last[i];
        int ret = query(1 , 1 , n , 1 , i-1);

        if(ret> l ) s.insert(i);
    }

    // for(auto x : s) cout<<x<<" ";
    // cout<<'\n';

    for(int i =1 ; ; i++ ) {
        if(s.find(i) == s.end()) {
            cout<<i<<'\n';
            return 0;
        }
    }
    

}