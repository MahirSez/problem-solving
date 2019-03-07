#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
vector<int>edg[MAX];
int  n , m;

int vis[MAX];

void bfs(int p) {

    queue<int>q;

    q.push(p);
    vis[p] = 1;

    while(!q.empty() ) {

        int node = q.front();
        q.pop();

        for(auto x : edg[node]) {
            if(vis[x]) continue;
            vis[x] = 1;
            cout<<node<<" "<<x<<'\n';
            q.push(x);
        }
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
        edg[v].push_back(u);
    }
    
    int id = -1;
    int mx = 0;

    for(int i =1 ; i <= n ; i++ ) {
        if( edg[i].size() > mx) {
            mx = edg[i].size() ; 
            id = i;
        }
    }
    // cout<<endl;

    bfs(id);
    return 0;
}
