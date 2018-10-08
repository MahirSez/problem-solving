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
int  n , m;
vector<int>edg[MAX];
int vis[MAX];
bool ok;
void dfs(int node , int par) {
    vis[node] = 1;
    for(int i = 0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if(x == par) continue;
        if( vis[x] == 1 ) ok = 1;
        else if( vis[x] == 0) dfs(x , node);
    }
    vis[node] = 2;
}


int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < m ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    int cnt = 0;
    for(int i =1 ; i<= n ;i++ ) {
        if( vis[i] == 0 ){
            ok = 0;
            dfs(i , -1);
            if( !ok ) cnt++;
        }

    }
    cout<<cnt<<endl;
    return 0;
}
