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

int n , m , a , b , c;
int dist[MAX][5];

void bfs(int rt,  int flg) {
    
    for(int i =1; i <= n ; i++ ) dist[i][flg] = -1;
    
    queue<int>q;
    dist[rt][flg] = 0;
    q.push(rt);
    while(!q.empty()) {
        
        int top = q.front();
        q.pop();
        
        for(auto x : edg[top]) {
            
            if(dist[x][flg] == -1) {
                dist[x][flg] = dist[top][flg] + 1;
                q.push(x);
            }
        }
    }
}


int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        cin>>n>>m>>a>>b>>c;
        int mm = m;
        vector<ll>vec(m) , sum(m+1);
        
        for(int i =1 ; i <=n ; i++ ) edg[i].clear();
        
        for(int i =0 ; i < m ; i++ ) cin>>vec[i];
        sort(vec.begin() , vec.end());
        for(int i =1 ; i <=m ; i++ ) sum[i] = sum[i-1] + vec[i-1];
        
        while(m--) {
            int u , v;
            cin>>u>>v;
            edg[u].push_back(v);
            edg[v].push_back(u);
        }
        bfs( b , 0);
        bfs( a , 1);
        bfs( c , 2);
        
        ll ans = INF;
        
        for(int i = 1;  i <=n ; i++ ) {
            
            ll tot = dist[i][0] + dist[i][1] + dist[i][2];
            if(tot > mm ) continue;
            
            ans = min(ans , sum[tot] + sum[ dist[i][0] ]);
            
        }
  
        cout<<ans<<'\n';
        
    }
    return 0;
}