#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m , ans;
vector<int>edg[MAX];
int vis[MAX] , dist[MAX];
stack<int>s;


void dfs1(int node ) {

    vis[node] = 1;
    for(auto x : edg[node]) {
        if( vis[x]) continue;
        dfs1(x);
    }
    s.push(node);
}

void dfs2(int node ,int h) {
    vis[node] = 1;
    ans = max(h , ans);

    for(auto x : edg[node]) {
        if( vis[x]) continue;
        dfs2(x, h+1);
    }
}

int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < m ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
    }

    for(int i = 1;  i<= n ; i++ ) {
        if( vis[i] ==0 ) dfs1(i);
    }
    memset(vis, 0 , sizeof vis);
    for(int i =1 ; i<= n ; i++ ) dist[i] = -INF;

    while( !s.empty()) {

        int top = s.top();
        s.pop();
//        cout<<top<<endl;

        if( dist[top ]== -INF) dist[top] = 0;
        for(auto x : edg[top]) {

            dist[x] = max(dist[x] , dist[top] + 1);
        }
    }
    for(int i =1 ; i <= n ; i++ ) ans = max(ans , dist[i]);
    cout<<ans<<endl;
    return 0;

}
