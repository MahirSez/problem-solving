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
int n  , cnt;
vector<int>edg[MAX];
int sz[MAX];
void dfs(int par , int node) {

    sz[node] = 1;
    for(int i =0 ; i < edg[node].size() ; i++ ) {

        int x = edg[node][i];
        if(x != par ) {
            dfs(node , x);
            sz[node] += sz[x];
            if( sz[x] % 2 == 0) cnt++;
        }
    }
}
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n -1 ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    if( n&1) cout<<-1<<endl;
    else {

        dfs(-1,1);
        cout<<cnt<<endl;
    }
    return 0;
}
