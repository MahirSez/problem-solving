#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e12
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int n , m ;
vector<int>edg[MAX];
vector<int>rev[MAX];
stack<int>st;
ll cnt , ans , cst[MAX] , tmp , mx;
int vis[MAX];

void dfs(int src) {
    vis[src] = 1;
    for(int i =0 ; i < edg[src].size() ; i++) {
        int node = edg[src][i];
        if( vis[node] == 0) {
            dfs(node);
        }
    }
    st.push(src);
}

void dfs1(int src) {

    vis[src] = 1;
    if( cst[src] < mx) {
        tmp=1;
        mx = cst[src];
    }
    else if( cst[src] == mx) {
        tmp++;
    }

    for(int i =0 ; i < rev[src].size() ; i++ ) {
        int node = rev[src][i];
        if( vis[node] == 0) {
            dfs1(node);
        }
    }
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i <= n ;i++ ) cin>>cst[i];
    cin>>m;
    for(int i =0 ; i < m ;i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        rev[v].push_back(u);
    }

    for(int i = 1 ; i<= n ; i++ ) {
        if( vis[i] == 0) dfs(i);
    }
    memset(vis, 0 , sizeof vis);
    ans = 1;
    while( !st.empty() ) {
        int node = st.top();
        st.pop();
        if( vis[node] == 0 ) {
            mx = INF;
            dfs1(node);
            cnt += mx;
            ans = (ans * tmp) % MOD;
        }
    }
    cout<<cnt<<" "<<ans<<endl;
    return 0;
}
