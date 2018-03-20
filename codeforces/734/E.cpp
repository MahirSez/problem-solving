#include <bits/stdc++.h>
#define ll			long long int
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
int n , mx,col[MAX] ,vis[MAX], lst;
vector<int>edg[MAX];

void dfs(int par , int lvl) {

    vis[par] = 1;
    for(int node : edg[par]) {

        if( vis[node] ) continue;

        if( col[par] == col[node] ) dfs(node , lvl);
        else dfs(node , lvl+1 );
    }

    if( lvl > mx ) {
        lst = par;
        mx = lvl;
    }
}

int main()
{
    fastRead;
    cin>>n;
    for(int i = 1;i<= n ;i++ )
        cin>>col[i];
    for(int i =0 ; i < n -1; i++ )  {

        int a , b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    dfs(1,1);
    memset(vis ,0 , sizeof(vis));
    dfs(lst , 1);
    cout<<(mx/2)<<endl;
    return 0;
}
