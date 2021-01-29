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


class segTree {
public:    
    vector<int>tree;
    int n;
    segTree(int nn) {
        tree = vector<int>(4*nn);
        n = nn;
    }
    int query(int l, int r) { return query(1 ,1 , n , l , r); }
    void update(int l, int r, int val) { update(1, 1, n, l, r, val); };
    int query(int node, int l, int r, int frm, int to) {
        if(l > r || l > to || r < frm) return 0; //change here
        if(l >= frm && r <= to ) return tree[node];
        int mid = (l+r)>>1;
        int q1 = query(node<<1, l, mid, frm, to);
        int q2 = query(node<<1|1, mid+1, r, frm, to);
        return max(q1 , q2); // change here
    }
    void update(int node, int l, int r, int frm, int to, int val) {
        if(l > r || l > to || r < frm) return ;
        if(l == r ) {
            tree[node] = val;
            return;
        }
        int mid = (l+r)>>1;
        update(node<<1, l, mid, frm, to, val);
        update(node<<1|1, mid+1, r, frm, to, val);
        tree[node] = max(tree[node<<1] , tree[node<<1|1]); // change here
    }
    void print() {
        for(int i =1 ; i <= n ; i++ ) cout<<query(i, i)<<" ";
        cout<<'\n';
    }
};

int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<pii>vec(n);
        vector<int>prev(n+1 , -1);
        for(int i =0 ; i < n ; i++ ) {
            cin>>vec[i].uu;
            vec[i].vv = i+1;
        }
        sort(vec.begin() , vec.end());

        set<int>s;
        for(int i =1 ; i <=n ; i++) s.insert(i);

        for(auto x : vec) {
            int id = x.vv;
            auto it = s.lower_bound(id);
            if(it != s.begin() ) {
                it--;
                prev[id] = *it;
            }
            s.erase(id);
        }

        segTree tree(n);

        int ans = 0;
        for(auto x : vec) {
            int id = x.vv;
            
            int val = 1 + tree.query( 1 , id-1) ;
            if(prev[id] != -1) val = max( val, 2 + tree.query(1, prev[id] - 1) );

            // cout<<x.uu<<" "<<x.vv<<" "<<val<<'\n';

            tree.update(id, id, val);
            // tree.print();
            ans = max(ans, val);
        }

        cout<<ans<<'\n';
    }
    return 0;

}