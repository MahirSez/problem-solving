#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define plp         pair<ll,pll>
#define ppp         pair<pll,pll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e4 + 5;
int n , m  ,s , c[MAX] , d[MAX];
vector<plp>edg[MAX];

ll dist[60][MAX] , ans[MAX];


struct node {

    int id ;
    ll _time , coin;
    node(int a ,ll  b ,ll c) {
        id = a;
        _time = b;
        coin = c;
    }
    
    
};

struct CompareAge {
    bool operator()(node const & p1, node const & p2) {
        // return "true" if "p1" is ordered before "p2", for example:
        return p1._time > p2._time;
    }
};

void dijk() {

    priority_queue<node , vector<node> , CompareAge > pq;
    
    for(int i = 0 ; i < MAX ; i++ ) {
        for(int j =1 ; j <=n ; j++ ) {
            dist[j][i] = INF;
        }
    }
    
    for(int i =2 ; i <=n ; i++ ) ans[i] = INF;
    
    s= min(s , MAX-1);
    dist[1][s] = 0;
    
    pq.push(node(1 , 0 , s));
    
    while(!pq.empty()) {
        
        
        node top = pq.top();
        pq.pop();
        
        int idNow = top.id;
        ll timeNow = top._time;
        ll coinNow = top.coin;
        if(timeNow < 0) continue;
        
        if(timeNow > dist[idNow][coinNow]) continue;
        
        
//        cout<<idNow<<" "<<timeNow<<" "<<coinNow<<'\n';
        
        ans[idNow] = min(ans[idNow] , timeNow);
                    
                    
        if(coinNow < MAX ) {
                
            ll newCoin = coinNow + c[idNow] ;
            ll newTm = timeNow + d[idNow];
            
            newCoin = min(newCoin , 1LL*MAX-1);
            
            
            if(dist[idNow][newCoin] > newTm) {
                dist[idNow][newCoin] = newTm;
                pq.push(node(idNow , newTm , newCoin ));
            }
        }
        
        for(auto x : edg[idNow]) {
            
            int id = x.uu;
            ll cst = x.vv.uu;
            ll tm = x.vv.vv;
            
            ll newCoin = coinNow - cst;
            ll newTm = timeNow + tm;
            
            if(newCoin < 0 ) continue;
            
            if(dist[id][newCoin] > newTm) {
               dist[id][newCoin] = newTm;
               pq.push(node(id , newTm , newCoin)) ;
            }
            
        }
    }
}



int main()
{
    fastRead;
    cin>>n>>m>>s;
    for(int i = 0 ; i < m ; i++ ) {
        int u , v , a , b;
        cin>>u>>v>>a>>b;
        edg[u].push_back({v , {a,b}});
        edg[v].push_back({u , {a,b}});
    }
    for(int i =1 ; i<=n ; i++ ) cin>>c[i]>>d[i];
    dijk();
    
    for(int i =2 ; i <=n ; i++ ) cout<<ans[i]<<'\n';
    return 0;
    
}