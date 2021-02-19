#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<ll,ll,ll, ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int N = 2e5 + 6;

int n, m;
ll dist[N][52][2];

vector<pll>edg[N];


void dijk() {

    for(int i = 1 ; i <= n ; i++ ) {
        for(int j =0; j <= 50 ; j++ ) {
            dist[i][j][0] = dist[i][j][1] = INF;
        }
    }

    dist[1][0][0] = 0;

    priority_queue<tp, vector<tp> , greater<tp> > pq;
    pq.push( {0, 0, 1, 0});

    while(!pq.empty()) {
        tp top = pq.top();
        pq.pop();
        ll topdst, topedgval, topnode, topflg;
        tie(topdst, topedgval, topnode,topflg) = top;

        // cout<<topnode<<" -- "<<topdst<<" "<<topedgval<<" "<<topflg<<'\n';

        if(dist[topnode][topedgval][topflg] != topdst) continue;
        if(topflg) {
            for(auto x : edg[topnode]) {
                ll edgcst = x.uu;
                ll childnode = x.vv;
                ll newdst = topdst + (edgcst + topedgval)* (edgcst + topedgval);

                if(dist[childnode][0][0] > newdst) {
                    dist[childnode][0][0] = newdst;
                    pq.push({newdst, 0, childnode, 0});
                }
            }
        }
        else {
            for(auto x : edg[topnode]) {
                ll edgcst = x.uu;
                ll childnode = x.vv;
                ll newdst = topdst;

                if(dist[childnode][edgcst][1] > newdst) {
                    dist[childnode][edgcst][1] = newdst;
                    pq.push({newdst, edgcst, childnode, 1});
                }
            }
        }
    }
}

int main()  {
    fastio;
    cin>>n>>m;
    while(m--) {
        int u, v, w;
        cin>>u>>v>>w;
        edg[u].push_back({w,v});
        edg[v].push_back({w,u});
    }

    dijk();
    for(int i =1 ; i <=n ; i++ ) {
        if(dist[i][0][0] == INF)dist[i][0][0] = -1;
        cout<<dist[i][0][0]<<" ";
    }
    cout<<'\n';
    return 0;
    
}