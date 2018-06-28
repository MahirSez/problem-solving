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
int n , d;
vector<int>edg[3000];
ll ans[3000] , tot ,  ara[3000];

void dfs(int node ,int par , int root) {
    ans[node] = 1;
    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if( x == par )continue;
        if( ara[x] < ara[root] || ara[x] > ara[root] + d ) continue;
        if( ara[x] == ara[root] && x > root ) continue;
        dfs(x , node , root);
        ans[node] = (ans[node] * (ans[x]+1LL) )% MOD;
    }
}

int main()
{
    fastRead;
    cin>>d>>n;
    for(int i = 1 ;i<= n ; i++ ) cin>>ara[i];
    for(int i =0 ; i < n-1 ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    for(int i =1 ;i<= n ; i++ ) {
        memset( ans , 0 , sizeof ans ) ;
//        cout<<i<<endl;
        dfs(i ,-1, i);

        tot = (tot + ans[i]) % MOD;
//        cout<<i<<" "<<ans[i]<<endl;
    }
    cout<<tot<<endl;
    return 0;
}
