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
ll n , m;

vector<pll>edg[MAX];

ll ara[MAX] , dist[MAX] , taken[MAX];


void solve() {

    
    priority_queue<pll , vector<pll> , greater<pll> > pq;
    
    
    for(int i =1 ;  i<=n ; i++ ) pq.push({ara[i] , i});
    
    
    while(!pq.empty()) {
        
        
        ll topnode = pq.top().vv;
        ll topwt = pq.top().uu;
        
        pq.pop();
        
        if(topwt > dist[topnode]) continue;
        
        for(auto x : edg[topnode]) {
            
            ll xx = x.uu;
            ll wt = x.vv;
            
            if(topwt + wt*2 < dist[xx]) {
                dist[xx] = topwt + wt*2;
                pq.push({dist[xx] , xx});
            }
        }
        
    }
}


int main()
{
    fastRead;
    cin>>n>>m;
    
    while(m--) {
        ll u , v , w;
        cin>>u>>v>>w;
        edg[u].push_back({v , w});
        edg[v].push_back({u , w});
    }
    
    for(int i= 1 ; i <=n ; i++ ) {
        cin>>ara[i];
        dist[i] = ara[i];
    }
    
    solve();
    
    for(int i =1 ; i <=n ; i++ ) cout<<dist[i]<<" ";
    cout<<'\n';
    
    
    return 0;
}