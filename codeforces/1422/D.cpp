#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e15;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int n , m;
vector<pii>edg[N];
int fx , fy;
int tx , ty;
vector<tp>pts;
ll dst[N];

void addEdges() {
    
    for(int i =0 ; i < m -1 ; i++) {
        int x1 , y1 , id1;
        int x2 , y2 , id2;
        tie(x1 , y1 , id1) = pts[i];
        tie(x2 , y2 , id2) = pts[i+1];

        int dist = min(abs(x1 - x2) , abs(y1 - y2));
        if(x1 == x2 || y1 == y2) dist = 0;

        edg[id1].push_back({id2 , dist});
        edg[id2].push_back({id1 , dist});
    }
}

bool comp(tp& pt1 , tp& pt2) {
    int x1 , y1 , id1;
    int x2 , y2 , id2;
    tie(x1 , y1 , id1) = pt1;
    tie(x2 , y2 , id2) = pt2;

    if(x1 == x2 && y1 == y2) return id1 < id2;
    if(y1 == y2) return (x1 < x2);
    return y1 < y2;
}

ll dijk(int frm , int to) {
    for(int i =0 ; i < N ; i++ ) dst[i] = INF;
    dst[frm] = 0;
    priority_queue<pll , vector<pll> , greater<pll> >pq;

    pq.push({0 , frm});

    while(!pq.empty()) {
        ll top , w;
        tie(w , top) = pq.top();
        pq.pop();

        if(dst[top] != w) continue;

        for(auto x : edg[top]) {
            int node, cst;
            tie(node , cst) = x;
            if(dst[node] > dst[top] + cst) {
                dst[node] = dst[top] + cst;
                pq.push({dst[node] , node});
            }
        }
    }
    // cout<<'\n';
    // for(int i= 1;  i <=m +2 ; i++) cout<<i<<" "<<dst[i]<<'\n';
    
    return dst[to];
}


int main() {
    fastio;
    cin>>n>>m;
    cin>>fx>>fy>>tx>>ty;
    int st = m + 1;
    int fn = m + 2;
    edg[st].push_back({fn , abs(fx - tx) + abs(fy - ty) });

    for(int i = 1; i <=m ; i++  ) {
        int x , y;
        cin>>x>>y;
        pts.push_back({x , y , i});

        edg[st].push_back({i , min( abs(x - fx) , abs(y - fy) )});
        edg[i].push_back({fn , abs(x - tx) + abs(y - ty) });
    }
    
    sort(pts.begin() , pts.end());
    addEdges();
    sort(pts.begin() , pts.end(), comp);
    addEdges();

    // for(int i =1 ; i <=m+2 ; i++ ) {
    //     cout<<i<<" ->\n";
    //     for(auto x : edg[i]) cout<<x.uu<<" "<<x.vv<<'\n';

    // }

    cout<<dijk(st , fn)<<'\n';
    return 0;

}