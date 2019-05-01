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
int n , totred , red[MAX] , lvl[MAX];

vector<pii>edg[MAX];

void dfs(int node , int par) {


    for(auto x: edg[node]) {

        int xx = x.uu;
        int green = x.vv;

        if( xx == par) continue;

        lvl[xx] = lvl[node] + 1;

		red[xx] = red[node];

		if( green ==0 )  {
			totred++;
			red[xx]++;
        }

        dfs(xx , node);


    }
}

int get(int node) {

    return totred - 2 * red[node] + lvl[node];
}


int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n-1 ; i++ ) {

		int u , v;
		cin>>u>>v;
		edg[u].push_back({v,1});
		edg[v].push_back({u,0});
    }
    dfs(1 , -1);

    int ans = INF;

    for(int i =1 ; i<= n ; i++ ) {

        ans = min(ans , get(i) ) ;
    }
    cout<<ans<<'\n';


    for(int i =1 ; i<= n ; i++ ) {
		if( get(i) == ans) cout<<i<<" ";
    }
    cout<<'\n';
    return 0;
}
