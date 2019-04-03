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
int n , m;
vector<int>edg[MAX];
vector<pii>lst;
int col[MAX];

bool dfs(int node,int clr) {

    col[node] = clr;
    bool ok = true;

    for(auto x : edg[node]) {
        if(col[x] == clr ) ok = false;
        if( col[x] == -1 ) ok &= dfs(x , clr^1);
    }

    return ok;
}


int main()
{
    fastRead;
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
        lst.push_back({u,v});
    }
    memset(col , -1 , sizeof col);
    bool ok = dfs(1,0);
    if( !ok ) {
		cout<<"NO\n";
		return 0;
    }
    cout<<"YES\n";

    for(auto x : lst) {

        if( col[x.uu]) cout<<0;
        else cout<<1;
    }
    cout<<endl;
    return 0;
}
