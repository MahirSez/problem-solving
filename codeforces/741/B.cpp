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
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m , cap;
int vis[MAX];
int val[MAX] , weight[MAX] , cnt;
vector<int>edg[MAX];
vector<int>grp[MAX];
int gval[MAX] , gwt[MAX];


void dfs(int node ) {
    grp[cnt].push_back(node);
    gwt[cnt] += weight[node];
    gval[cnt] += val[node];

    vis[node] = 1;
    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if( vis[x]) continue;
        dfs(x);
    }
}

int dp[5000][5000];

int solve(int id , int taken) {
    if( id == cnt ) {
        return 0;
    }
    int &ret = dp[id][taken];
    if( ret != -1) return ret;

    ret = 0;

    for(int i =0 ; i < grp[id].size() ; i++) {
        int node = grp[id][i];
        if( weight[node] + taken <= cap ) ret = max( ret , val[node] + solve(id+1 , taken + weight[node]) );
    }
    if( taken + gwt[id] <= cap) ret = max(ret , gval[id] + solve(id+1 , taken + gwt[id]));
    ret = max(ret , solve(id+1 , taken));
    return ret;
}

int main()
{
    fastRead;
    cin>>n>>m>>cap;
    for(int i =1 ; i <= n ; i++ ) {
        cin>>weight[i];
    }
    for(int i =1 ; i <= n ; i++ ) {
        cin>>val[i];

    }
    while( m-- ) {
        int a , b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    for(int i = 1 ; i <= n ; i ++ ) {
        if(vis[i]) continue;
        dfs(i);
        cnt++;
    }

    memset(dp , -1 , sizeof dp);
    cout<<solve(0 , 0)<<endl;
    return 0;
}

