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

int n ,m , x , y , z;
int red , blu;
int vis[MAX] , col[MAX] , ans[MAX];
vector<int>edg[MAX] , compMem[MAX];
vector<pii>v1;

bool dfs(int node , int c , int id) {
    
    if(c == 1) red++;
    else blu++;
    col[node] = c;
    vis[node] = 1;
    
    compMem[id].push_back(node);
    
    bool ok = 1;
    for(auto xx : edg[node]) {
        if(vis[xx] == 0 ) dfs(xx , c^1 , id);
        else if(col[xx] == c) ok = 0;
    }
    return ok;
}

int dp[5005][5005];

int main()
{
    fastRead;
    cin>>n>>m>>x>>y>>z;
    
    for(int i =0 ; i <m ;i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    for(int i = 1 ;i <=n ; i++ ) {
            
        if(vis[i]) continue;
        red = 0;
        blu = 0;
        
        bool ok = dfs(i , 1 , v1.size());
        if(!ok) {
            cout<<"NO\n";
            return 0;
        }
        v1.push_back({red , blu});
    }
    
//    cout<<v1.size()<<'\n';
//    for(auto xx : v1) cout<<xx.uu<<" "<<xx.vv<<'\n';
    
    int nn = v1.size();
    dp[0][0] = 1;
    
    for(int i = 1; i <=nn ; i++ ) {
        
        for(int sum = 0;sum <= n ; sum ++ ) {
            
            if(sum - v1[i-1].uu >= 0) dp[i][sum] |= dp[i-1][sum - v1[i-1].uu] ;
            if(sum - v1[i-1].vv >= 0) dp[i][sum] |= dp[i-1][sum - v1[i-1].vv] ;
        }
    }
    
    if(dp[nn][y] == 0 ) {
        cout<<"NO\n";
        return 0;
    }
    
    cout<<"YES\n";
    
    int now = y;
    for(int i = nn ; i>=1 ; i--) {
        
        int rnow = v1[i-1].uu;
        int bnow = v1[i-1].vv;
        
        if(now-rnow >=0 && dp[i-1][now - rnow]) {
            now-= rnow;
            
            for(auto xx : compMem[i-1]) {
                if(col[xx] == 1) ans[xx] = 2;
            }
        }
        else if(now - bnow >=0 && dp[i-1][now -bnow]) {
            
            now-= bnow;
            for(auto xx : compMem[i-1]) {
                if(col[xx] == 0) ans[xx] = 2;
            }
        }
        else assert(0);
    }
    
    for(int i =1 ; i <=n ; i++ ) {
        if(ans[i] ==2) cout<<2;
        else if(x > 0) {
            cout<<1;
            x--;
        }
        else if(z > 0) {
            cout<<3;
            z--;
        }
    }
    cout<<'\n';

    return 0;
    
    
    
}