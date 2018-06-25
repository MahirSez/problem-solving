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
int n , m , deg[MAX] , mx , vis[MAX] ;
vector<int>edg[MAX];
ll ans ,wht , blk ;
bool ok;

void dfs(int node,int col) {
    vis[node] = col;
    if( col == 1 ) wht++;
    else blk ++;
    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if( vis[x] == -1) {
            dfs(x , col^1);
        }
        else if( vis[x] == vis[node]) {
            ok = false;
        }
    }
}

int main()
{
    fastRead;
    cin>>n>>m;
    if( m == 0) {
        ans =n;
        ans *= (n-1);
        ans *= (n-2);
        ans/=6;
        cout<<3<<" "<<ans<<endl;
        return 0;
    }
    for(int i =0 ; i < m ; i++) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
        deg[u]++;
        deg[v]++;
        mx = max(mx , deg[u]);
        mx = max(mx , deg[v]);
    }
    if( mx == 1  ) {
        ll ans = m ;
        ans *= (n-2);
        cout<<2<<" "<<ans<<endl;
        return 0;
    }
    memset( vis , -1 , sizeof vis);
    ll ans = 0;
    for(int i =1 ; i<= n ; i++ ) {
        if(vis[i] ==-1 ) {
            ok = true;
            wht = 0 , blk = 0;
            dfs(i ,  1);
            if( !ok ) {
                cout<<0<<" "<<1<<endl;
                return 0;
            }
            ans += (wht)*(wht-1)/2 + (blk)*(blk-1)/2 ;

        }
    }
    cout<<1<<" "<<ans<<endl;
    return 0;
}
