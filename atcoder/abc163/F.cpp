#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
vector<int>edg[MAX] , vec[MAX] , rec[MAX];
int col[MAX] , sz[MAX];

void dfs(int node, int p) {
    
    int prevsz = vec[col[node]].size();
    sz[node] = 1;
    
    for(auto x : edg[node]) {
        if(x == p) continue;
        dfs(x , node);
        sz[node] += sz[x];
        
        int tmp = sz[x];
        for(int i = prevsz ; i < vec[ col[node] ].size() ; i++ ) {
            tmp -= vec[ col[node] ][i];
        }
        while(vec[col[node]].size() > prevsz) vec[col[node]].pop_back();
        
        rec[col[node]].push_back(tmp);
    }
    vec[col[node]].push_back(sz[node]);
    
}

ll get(ll n) {
    
    return (n*(n-1) )/2 + n;
}

int main()
{
    fastRead;
    int n;
    cin>>n;
    for(int i =1 ; i <=n ; i++ ) cin>>col[i];
    
    for(int i =1 ; i < n ;i++) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    edg[0].push_back(1);
    
    dfs(0 , -1  );


    for(int i =1 ; i <=n ; i++ ) {
        int val = sz[1];
        for(auto x : vec[i]) val -= x;
        rec[i].push_back(val);
    }
    
    for(int i =1 ; i <=n ; i++ ) {
        ll ans = get(n);
        for(auto x : rec[i]) ans -= get(x);
        cout<<ans<<'\n';
    }
        
//    for(int i =1 ;i <=n ; i++  ) {
//        cout<<i<<" -- \n";
//        for(auto x : rec[i]) cout<<x<<" ";
//        cout<<'\n';
//    }
    return 0;
}