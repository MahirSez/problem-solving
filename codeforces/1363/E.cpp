#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
vector<int>edg[MAX];

ll a[MAX] , b[MAX] , c[MAX] ;
int ab[MAX], ba[MAX];

ll ans = 0;

void dfs1(int node , int p) {
    
    for(auto x: edg[node]) {
        if(x == p) continue;
        a[x] = min(a[node], a[x]);
        dfs1(x, node);
    }
}

void dfs2(int node, int p) {
    
    if(b[node] != c[node]) {
        if(b[node] == 0 ) ab[node]++;
        else ba[node]++;
    }
    for(auto x: edg[node]) {
        
        if(x == p) continue;
        dfs2(x, node);
        ab[node] += ab[x];
        ba[node] += ba[x];
    }
    
    int mn = min(ab[node], ba[node]);
    ab[node] -= mn;
    ba[node] -= mn;
    ans += a[node]*mn*2;
}



int main()
{
    fastRead;
    int n;
    cin>>n;
    
    for(int i = 1 ; i <=n ; i++ ) {
        cin>>a[i]>>b[i]>>c[i];
    }
    
    for(int i = 1 ; i < n ; i++ ) {
        
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    dfs1(1 , 0);
    dfs2(1, 0);
    
    if(ab[1] || ba[1]) ans = -1;
    cout<<ans<<'\n';
    return 0;
}