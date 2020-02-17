#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int n , m , k;

int mark[MAX] , dst[MAX][2] ;

vector<int>edg[MAX];
vector<pii>rec;

void bfs(int node , int flg) {

    for(int i = 1 ; i <=n ; i++ ) dst[i][flg] = INF;
    
    queue<int>q;
    dst[node][flg] = 0;
    q.push(node);
    
    while(!q.empty()) {
        
        int top = q.front();
        q.pop();
        
        for(auto x : edg[top]) {
            if(dst[x][flg] == INF) {
                dst[x][flg] = dst[top][flg] + 1;
                q.push(x);
            }
        }
    }
    
//    for(int i =1; i  <=n ; i++ ) cout<<" "<<i<<" "<<dst[i][0]<<'\n';
//    cout<<'\n';    
}



int solve() {
    
    for(int i =1 ; i <=n ; i++ ) {
        if(mark[i]) rec.push_back({dst[i][0] , i});
    }
    sort(rec.begin() , rec.end());
    
    int ret = 0;
    
    
    for(int i =1; i < rec.size(); i++ ) {
        int node1 = rec[i].vv;
        int node2 = rec[i-1].vv;
        int tmp1 = dst[node1][0] + dst[node2][1] + 1;
        int tmp2 = dst[node1][1] + dst[node2][0] + 1;
        ret = max(ret ,  min(tmp1 , tmp2) );
    }
    
    
    return min(ret , dst[n][0] );
    
    
}




int main()
{
    fastRead;
    
    cin>>n>>m>>k;
    
    for(int i = 1 ; i <=k ; i++ ) {
        int tmp;
        cin>>tmp;
        mark[tmp] = 1;
    }
    
    for(int i =1;  i <= m ; i++) {
        
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }

    
    bfs(1 , 0);
    bfs(n , 1);
    
//    for(int i =1; i  <=n ; i++ ) cout<<i<<" "<<dst[i][0]<<'\n';
//    cout<<'\n';
//    for(int i =1; i  <=n ; i++ ) cout<<i<<" "<<dst[i][1]<<'\n';
    
//    dfs(n ,  dst[n]);
    
    cout<<solve()<<'\n';
    return 0;
    
}