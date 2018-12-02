#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pip         pair<int, pii>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n,  par[3000] , sz[3000];
int src;
ll ara[3000][3000] ;
vector<pip>v;
vector<pii>edg[3000];

int boss(int x) {

    if( par[x] == x) return x;
    return par[x] = boss(par[x]);
}

void dfs(int node ,int par , int wt) {

    if( ara[src][node] != wt) {
        cout<<"NO"<<endl;
        exit(0);
    }
    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i].vv;
        int w = edg[node][i].uu;
        if( x == par ) continue;
        dfs(x , node, wt+w);
    }
}

int main()
{
    cin>>n;
    for(int i = 0 ; i < n ; i++ ) {
        for(int j = 0; j < n ; j++ ) {
            scanf("%I64d",&ara[i][j]);
        }
    }

    for(int i = 0; i < n ; i++ ) {
        for(int j = i+1 ; j< n ; j++ ) {
            if( ara[i][j] != ara[j][i]) {
                cout<<"NO"<<endl;
                return 0;
            }
            else if(i < j && ara[i][j]) v.push_back(pip(ara[i][j] , {i,j}));

        }
    }
    sort(v.begin() , v.end()) ;
    int cnt = 0;
    for(int i =0 ; i < n ; i++ ) {
        par[i]  =i;
        sz[i] = 1;
    }

    for(int i =0 ; i < v.size() ; i++ ) {
        int w = v[i].uu;
        int u = v[i].vv.uu;
        int x = v[i].vv.vv;

        int uu = boss(u);
        int vv = boss(x);
        if( uu != vv) {
            if(sz[uu] >= sz[vv]) {
                par[vv] = uu;
                sz[uu] += sz[vv];
            }
            else {
                par[uu] = vv;
                sz[vv] += sz[uu];
            }
            edg[u].push_back({w , x});
            edg[x].push_back({w , u});
            cnt++;
        }
    }
    if( cnt!= n-1) {
        cout<<"NO"<<endl;
        return 0;
    }

    for(int i = 0 ; i < n ; i++ ) {
        src  = i;
        dfs(i , -1 ,0 );
    }
    cout<<"YES"<<endl;
    return 0;
}
