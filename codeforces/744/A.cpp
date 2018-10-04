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
int n , m , k;
int cap[10004];
int edg[1003][1003];
int vis[10004];
int cnt  ,ans , tot , tmp;

void calc(int node) {
    vector<int>v;
    v.push_back(node);
    vis[node] = 1;


    for(int i =0 ; i < v.size() ; i++ ) {
        node = v[i];
        for(int j =1 ; j <= n ; j++ ) {
            if( edg[node][j]) {
                tmp++;
                if( vis[j] ) continue;
                vis[j] = 1;
                v.push_back(j);
            }
        }
    }

    cnt = v.size() ;
    tmp /=2;

}

int main()
{
    fastRead;
    cin>>n>>m>>k;
    for(int i =0 ; i < k ; i++ ) cin>>cap[i];
    for(int i =0 ; i < m ; i++ ) {
        int u  , v;
        cin>>u>>v;
        edg[u][v] = 1;
        edg[v][u] = 1;
    }
    int mx = 0;
    for(int i =0 ; i < k ; i++ ) {
        cnt = 0;
        tmp = 0;
        calc(cap[i]);
        mx = max( mx , cnt);
        ans += (cnt * (cnt-1) / 2 ) - tmp;
    }

    for(int i = 1; i<=n ; i++ ) {
        cnt = 0;
        tmp = 0;
        if( vis[i] == 0 ) {
            calc(i);
            ans += (cnt * (cnt-1) / 2) - tmp;
            ans += mx * cnt;
            mx += cnt;
        }
    }
    cout<<ans<<endl;
    return 0;
}
