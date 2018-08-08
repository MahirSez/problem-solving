#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int  n , m ,par[MAX] , lvl[MAX], table[MAX][20];
int tree[4*MAX] , lazy[4*MAX] , pos[MAX] , val[MAX];
vector<int>edg[MAX] , euler;
vector<pii>str;
map<pii,int>mp;
map<int,pii>mp1;

void dfs(int node ,int parent , int level) {
    lvl[node] = level;
    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if( x == parent ) continue;
        euler.push_back(x);
        mp[{node,x}] = x;
        mp[{x,node}] = x;
        mp1[x] = {x, node};
        par[x] = node;
        dfs(x , node , level + 1);
    }
    euler.push_back(-node);
}

void build()
{
    memset( table, -1 , sizeof table);
    for(int i = 1 ;i<= n ; i++ ) {
        table[i][0] = par[i];
    }

    for(int j =1 ; (1<<j) <= n ; j++ ) {
        for(int i = 1 ; i<= n ; i++ ) {
            if( table[i][j-1] != -1) {
                table[i][j] = table[ table[i][j-1] ][j-1] ;
            }
        }
    }

}

int query(int u , int v) {

    if( lvl[u] < lvl[v]) swap(u,v);

    while( lvl[u] > lvl[v]) {
        int logDst = log2(lvl[u] - lvl[v]);
        u = table[u][logDst];
    }
    if( u == v) return u;
    for(int logVal = log2(lvl[u]) ; logVal >= 0 ; logVal-- ) {
        if( table[u][logVal]!= -1 && table[u][logVal] != table[v][logVal]) {
            u = table[u][logVal];
            v = table[v][logVal];
        }
    }
    return par[u];
}


void push(int node , int l , int r ) {
    if( lazy[node]) {
        tree[node] += lazy[node];
        if( l != r) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
    }
    lazy[node] = 0;
}

void update(int node ,int l ,int r, int frm ,int to  , int val) {
    push(node ,l , r);
    if( l > r || l > to || r < frm ) return;
    if( l >=frm && r <= to ) {
        lazy[node] += val;
        push(node, l  ,r );
        return ;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , frm , to , val);
    update(node<<1|1 , mid+1 , r , frm , to , val);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

int query(int node ,int l , int r , int frm , int to) {
    push(node , l , r);
    if( l>r || l > to || r < frm ) return 0;
    if(l >= frm && r <= to ) {
        return tree[node];
    }
    int mid = (l+r)>>1;
    int q1 = query(node<<1 , l , mid , frm , to);
    int q2 = query(node<<1|1 , mid+1 , r ,frm , to);
    return q1 + q2;
}


void print()
{
    for(int i =1 ; i < 20 ; i++ )
        cout<<tree[i]<<" ";
    cout<<endl;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n -1 ; i++ ) {
        int a , b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
        str.push_back({a,b});
    }
    euler.push_back(1);
    dfs(1 , -1 , 0);
    for(int i =0 ; i < euler.size() ; i++ ) {
        if( euler[i] > 0 ) {
            pos[euler[i]] = i;
        }
//        cout<<euler[i]<<" ";
    }
//    cout<<endl;
    build();
    cin>>m;
    int sz = euler.size();
    while( m-- ) {
        int frm , to;
        cin>>frm>>to;

        int lca = query(frm , to);
//        cout<<frm<<" "<<to<<" "<<lca<<endl;
        frm = pos[frm];
        to = pos[to];
        lca = pos[lca];
//        cout<<frm<<" "<<to<<" "<<lca<<endl;
        update(1 ,0 , sz-1 , 0 , frm , 1);
        update(1 ,0 , sz-1 , 0 , to , 1);
        update(1 ,0 , sz-1 , 0 , lca ,-2);
//        cout<<"----> "<<query(1 , 0, sz-1 , 0 , 1)<<endl;
//        cout<<"----> "<<query(1 , 0, sz-1 , 0 , 2)<<endl;
//        cout<<"----> "<<query(1 , 0, sz-1 , 0 , 3)<<endl;
    }
    int now = 0;
    for(int i = 1 ; i < sz ; i++ ) {
        int get = query(1 , 0 , sz-1 , i , i );
        if( euler[i] > 0 ) {
            val[euler[i]] += get;
        }
        else {
            val[-euler[i]] -= get;
            int frm = mp1[-euler[i]].uu;
            int to = mp1[-euler[i]].vv;
            mp[{frm,to}] = val[-euler[i]];
            mp[{to,frm}] = val[-euler[i]];
        }
//        cout<<euler[i]<<" ---- "<<now<<endl;
    }

    for(int i =0 ; i< str.size() ; i++ ) {
        int frm = str[i].uu;
        int to = str[i].vv;
        cout<<mp[{frm , to}]<<" ";

    }
    cout<<endl;
    return 0;
}
