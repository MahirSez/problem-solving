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
int  n , m , k;
vector<int>edg[MAX] , v;
int vis[MAX] ;

void dfs(int node) {
    vis[node] = 1;

    for(int i =0 ; i < edg[node].size() ; i++) {

        int x = edg[node][i];
        if( vis[x]) continue;
        v.push_back(x);
        dfs(x);
        v.push_back(node);
    }

}
int main()
{
    fastRead;
    cin>>n>>m>>k;
    for(int i =0 ; i < m ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    v.push_back(1);
    dfs(1);

    int per = (2*n-1)/k + 1;
    int now = 0;

    for(int i =0 ; i < k ; i++ ) {

        int cnt = min(per , 2*n - 1 - now ) ;


        if( cnt == 0 ) {
            cout<<"1 1\n";
            continue;
        }

        cout<<cnt<<" ";

        for(int j = 0 ; j < cnt ; j++ ,now++) {

            cout<<v[now]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
/*
5 9
1 2
1 4
2 4
4 4
4 5
4 5
5 3
3 3
3 2
*/
