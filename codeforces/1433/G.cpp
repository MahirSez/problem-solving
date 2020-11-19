#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e3 + 6;
vector<pii>edg[N];
int dist[N][N], tmpdist[N];
int n, m, k;
int x1= -1, x2= -1;

void dijk(int src) {

    dist[src][src] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, src});
    while(!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        int topNode, topDist;
        tie(topDist, topNode) = top;

        if(topDist != dist[src][topNode]) continue;

        for(auto x : edg[topNode]) {
            int wt, node;
            tie(wt, node) = x;

            if(dist[src][node] > topDist + wt) {
                dist[src][node] = topDist  + wt;
                pq.push({dist[src][node], node});
            }
        }
    }
}

void dijk1(int src) {

    tmpdist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, src});
    while(!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        int topNode, topDist;
        tie(topDist, topNode) = top;

        if(topDist != tmpdist[topNode]) continue;

        for(auto x : edg[topNode]) {
            int wt, node;
            tie(wt, node) = x;

            if(topNode == x1 && node == x2) wt = 0;
            if(topNode == x2 && node == x1) wt = 0;

            if(tmpdist[node] > topDist + wt) {
                tmpdist[node] = topDist  + wt;
                pq.push({tmpdist[node], node});
            }
        }
    }
}

vector<pii>rec;

int main() {
    fastio; 
    cin>>n>>m>>k;
    for(int i =1 ; i <=n ; i++ ) {
        for(int j =1 ; j <=n ; j++ ) dist[i][j] =  INF;
    }
    for(int i =0 ; i < m ; i++ ) {
        int u , v , w;
        cin>>u>>v>>w;
        edg[u].push_back({ w, v});
        edg[v].push_back({ w, u});
    }

    for(int i = 1; i <=n ; i++ ) dijk(i);

    // for(int i =1 ; i <=n ; i++ ) {
    //     for(int j =1 ; j <=n ; j++ ) {
    //         cout<<dist[i][j]<<"\t";
    //     }
    //     cout<<'\n';
    // }
    // return 0;

    for(int i =0 ; i < k ; i++ ) {
        int u , v;
        cin>>u>>v;
        rec.push_back({u,v});
    }

    int ans = INF;
    

    for(int i =1 ; i <=n ; i++ ) {
        for(auto &x : edg[i]) {
            
            
            x1 = i;
            x2 = x.vv;

            // cout<<" "<<x1<<" "<<x2<<endl;


            for(int j =1 ; j <=n ; j++ ) tmpdist[j] = dist[i][j];

            dijk1(i);
            int sum = 0;

            for(auto xx : rec) {
                int u, v;
                tie(u, v) = xx;
                
                // assert(dist[u][v] == dist[v][u]);

                int prevDst = dist[u][v];
                int newDst = tmpdist[u] + tmpdist[v];
                sum += min(prevDst, newDst);
            }
            ans = min(ans, sum);

            x1 = x2 = -1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}