#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int n , m , u , v;
vector<int>edg[MAX];
bool vis[MAX] , ok;

void dfs(int node) {

    vis[node]= true;

    if( edg[node].size() != 2) ok = false;
    for(int i =0 ; i < edg[node].size() ; i++ ) {

        int x  = edg[node][i];
        if( vis[x] == false) dfs(x);
    }
}

int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < m ;i++ ) {
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    int cnt = 0;
    for(int i = 1; i <=n ; i++ ) {
        if( vis[i] == false) {
            ok = true;
            dfs(i);
            if( ok) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
