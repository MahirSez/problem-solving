#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<ll , ll>
#define ppi         pair<pii , ll>
#define INF     	1000000000000000000
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll n , m , s , t;
vector<pii>edg[MAX] ;
ll dist[MAX] , l;
vector< pii > str;
vector< ppi >rec;

void dijk() {

    for(int i = 0 ; i < n ; i++) dist[i] = INF;

    priority_queue<pii , vector<pii> , greater<pii> > pq;
    pq.push({0 , s});
    dist[s] = 0;
    while( !pq.empty() ) {

        int top = pq.top().vv;
        pq.pop();
        for(int i = 0 ; i < edg[top].size() ; i++ ) {
            ll node= edg[top][i].vv;
            ll wt = edg[top][i].uu;
            if(dist[node] > dist[top] + wt) {
                dist[node] = dist[top] + wt;
                pq.push({dist[node] , node});
            }
        }
    }
}


int main()
{
    fastRead;
    cin>>n>>m>>l>>s>>t;
    for(int i =0 ; i < m ; i++ ) {
        int u , v , w;
        cin>>u>>v>>w;
        if( w ) {
            edg[u].push_back({w,v});
            edg[v].push_back({w,u});
            rec.push_back({{u,v} , w});
        }
        else str.push_back({u,v});
    }
    dijk();
//    cout<<dist[t]<<endl;
    if( l > dist[t] ) {
        cout<<"NO"<<endl;
        return 0;
    }
    int id = -1;
    int extra = 0;
    while(  dist[t] > l ) {
        id++;
        if( id == str.size()) break;
        int u = str[id].uu;
        int v = str[id].vv;
        edg[u].push_back({1 , v});
        edg[v].push_back({1 , u});
        dijk();
        extra = l - dist[t];
    }
//    cout<<dist[t]<<endl;
    if( dist[t] > l ) {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i =0 ; i < rec.size() ; i++ ) {
        cout<<rec[i].uu.uu<<" "<<rec[i].uu.vv<<" "<<rec[i].vv<<'\n';
    }
    for(int i =0 ; i < str.size() ; i++ ) {
        if( i < id ) cout<<str[i].uu<<" "<<str[i].vv<<" 1\n";
        else if( i == id) cout<<str[i].uu<<" "<<str[i].vv<<" "<<extra+1<<'\n';
        else cout<<str[i].uu<<" "<<str[i].vv<<" "<<INF<<'\n';
    }
    cout<<endl;
    return 0;
}
