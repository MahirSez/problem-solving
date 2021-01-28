/**
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get min element within range [i, j]
 */

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

int ara[N] , tree[4*N] ,lazy[4*N];

void build(int node ,int l ,int r ) {
    if( l == r) {
        tree[node] = ara[l];
        lazy[node] = -1;
        return;
    }
    int mid = (l+r)>>1;
    build( node<<1 , l , mid);
    build(node<<1|1 , mid + 1 , r);
    tree[node] = tree[node<<1] + tree[node<<1|1];
    lazy[node] = -1;
}

void print(int node , int l, int r) {

    cout<<node<<" "<<l<<" "<<r<<" ->"<<tree[node]<<'\n';
    if(l >= r) return ;
    int mid= (l+r)/2;
    print(node<<1, l , mid);
    print(node<<1|1 , mid+1 , r);

}




void push(int node ,int l ,int r) {
    if( lazy[node] != -1) {
        tree[node] = lazy[node] * (r-l+1);
        if( l !=r) {
            lazy[node<<1] = lazy[node];
            lazy[node<<1|1] =lazy[node];
        }
        lazy[node] = -1;
    }
}


void update(int node ,int l, int r, int frm, int to ,int val) {
    push(node, l , r);
    if( l > r || l > to || r < frm ) return ;
    if( l >=frm && r <= to) {
        lazy[node] = val;
        push(node, l , r);
        return ;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , frm , to , val);
    update(node<<1|1 , mid+1 , r , frm ,to , val);
    tree[node] =  tree[node<<1] + tree[node<<1|1] ;
}

int query(int node, int l , int r ,int frm ,int to ) {
    push(node, l , r);
    if( l > r || l > to || r < frm ) return 0;
    if( l >= frm && r <= to ) return tree[node] ;
    int mid = (l+r)>>1;
    int q1 = query(node<<1 , l , mid , frm ,to);
    int q2 = query(node<<1|1 , mid+1 , r , frm , to);
    return q1 + q2;
}

void print(int n) {
     for(int k =1 ; k <=n ; k++ ) {
        cout<<query(1, 1 , n , k , k )<<" ";
    }
    cout<<'\n';
}

int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {

    
        int n, q;
        cin>>n>>q;
        string s1, s2;
        cin>>s1>>s2;

        vector<int>rec(n+1), l(q) , r(q);

        for(int i =1 ; i <= n ; i++ ) {
            ara[i] = s2[i-1] - '0';
            rec[i] = s1[i-1] - '0';
        }

        build(1 , 1 , n);

        for(int i =0; i < q ; i++ ) {
            cin>>l[i]>>r[i];
        }
        int ok = 1;

        // print(n);

        for(int i = q -1; i>=0 ; i--) {

            int len = r[i] - l[i] + 1;
            int ones = query(1, 1 , n , l[i], r[i]);
            int zeros = len - ones;
            if(ones == zeros) {
                ok = 0;
                break;
            }


            if(ones > zeros) update(1 , 1 , n , l[i] , r[i] , 1);
            else update(1 , 1 , n , l[i] , r[i] , 0);

            // print(n);
        }

        for(int i =1; i <=n ; i++  ) {
            if(query(1 ,1 , n , i , i) != rec[i]) ok = 0;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}

