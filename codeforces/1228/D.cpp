#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int vis[N] , col[N];
vector<int>edg[N];

map<pii,int>mp;
void dfs(int node, int p) {

    vis[node] = 1;

    int col1 = col[node];
    int col2 = col[p];
    int col3 = -1;
    for(int i =1 ; i <=3 ; i++ ) {
        if(col1 !=i && col2 != i) col3 = i;
    }
    assert(col3 != -1);

    for(auto x : edg[node]) {
        if(vis[x]) continue;
        if( mp[{x , p}]) col[x] = col3;
        else col[x] = col[p];
        dfs(x , node);
    }
}

int fre[5];

int main()  {
    fastio;
    int n ,m;
    cin>>n>>m;
    while(m--) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);

        mp[{u,v}] = mp[{v,u}] = 1;
    }

    if(edg[1].size()== 0) {
        cout<<-1<<'\n';
        return 0;
    }

    int frm = edg[1][0];
    memset(col , -1 , sizeof col);

    col[1] = 1;
    col[frm] = 2;

    vis[1] = vis[frm] = 1;

    dfs(frm , 1);


    for(int i =1 ; i <=n ;i++ ) {
        if(vis[i] == 0) {
            cout<<-1<<'\n';
            return 0;
        }

        for(auto x : edg[i]) {
            if(col[x] == col[i]) {
                cout<<-1<<'\n';
                return 0;
            }
        }

        fre[col[i]]++;
    }

    
    for(int i =1 ; i <= 3 ; i++ ) {
        if(fre[i] == 0 ) {
            cout<<-1<<'\n';
            return 0;
        }
    }

    for(int i =1 ; i <=n ;  i++ ) {

        int nn = edg[i].size();

        if(n - nn != fre[col[i]]) {
            cout<<-1<<'\n';
            return 0;
        }
    }


    

    for(int i =1 ; i <=n ; i++ ) cout<<col[i]<<" ";
    cout<<'\n';
    return 0;
    


}