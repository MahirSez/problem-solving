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
int n , m , q , par[MAX] , len[MAX] ,lev[MAX], mx ,side;
vector<int>edg[MAX];

void dfs1(int node ,int parent , int lvl ,int root) {
    lev[node] = lvl;
    if( lvl > mx ) {
        mx = lvl;
        side = node;
    }
    for(int i = 0; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if( x == parent) continue;
        par[x] = root;
        dfs1(x , node , lvl+1 , root);
    }
}

int boss(int x) {
    return ( (par[x]==x) ? x : par[x] = boss(par[x]) );
}

int main()
{
    fastRead;
    cin>>n>>m>>q;
    for(int i =0 ; i < m ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    for(int i =1 ; i<= n ;i++ ) par[i] = i;
    for(int i =1 ; i<= n ;i++)  {
        if( par[i] == i) {
            mx = 0;
            side = i;
            dfs1(i ,-1, 0,i);
            mx = 0;
            dfs1(side,-1,0,i);
            len[i] = mx;
        }
    }

    while( q-- ) {
        int tmp;
        cin>>tmp;
        if( tmp == 1 ){
            int x;
            cin>>x;
            cout<<len[boss(x)]<<endl;
        }
        else {
            int u , v;
            cin>>u>>v;
            int uu = boss(u);
            int vv = boss(v);
            if( uu == vv ) continue;
            par[vv] = uu;

            int l = ceil(len[uu]*1.00/2) + ceil(len[vv]*1.00/2) + 1;
            len[uu] = max( len[uu] , max(len[vv] , l) );
        }
//        for(int i =1 ; i<=n ; i++ ) {
//            printf("%d ",len[boss(i)]);
//        }
//        printf("\n");
    }
    return 0;
}

