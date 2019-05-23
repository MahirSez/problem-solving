#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , sz[MAX] , anslvl[MAX] , lvl[MAX] , fre[MAX];
vector<int>edg[MAX] , *vec[MAX];

void dfs1(int node , int par , int lev ){

    lvl[node] = lev;
    sz[node] = 1;
    for(auto x : edg[node]) {

        if( x == par) continue;
        dfs1(x , node , lev+1);
        sz[node] += sz[x];
    }
}

void dfs2(int node , int par , int keep) {

    int big = -1;
    for(auto x : edg[node]) {
        if( x == par) continue;
        if( big == -1 || sz[x] > sz[big]) big = x;
    }

    for(auto x: edg[node]) {
        if(x == big || x == par) continue;
        dfs2(x , node , 0);
    }

    anslvl[node] = lvl[node];

    if( big == -1) vec[node] = new vector<int>();
    else {
        dfs2(big , node , 1);
        vec[node] = vec[big];
        anslvl[node] = anslvl[big];
    }

    vec[node] ->push_back(node);
    fre[ lvl[node] ]++;

    if( fre[lvl[node]] > fre[anslvl[node] ] ) {
        anslvl[node] = lvl[node];
    }
    else if( fre[lvl[node]] == fre[anslvl[node] ] ) {
        anslvl[node] = min(anslvl[node] , lvl[node] );
    }

    for(auto x : edg[node]) {
        if( x == par || x == big) continue;

        for(auto xx : *vec[x]) {

            fre[lvl[xx]]++;
            vec[node]->push_back(xx);

            if( fre[lvl[xx]] > fre[anslvl[node]] ) {
                anslvl[node] = lvl[xx];
            }
            else if( fre[lvl[xx]] == fre[anslvl[node]] ) {
                anslvl[node] = min(anslvl[node] , lvl[xx]);
            }
        }
    }

    if( keep == 0 ) {

        for(auto x : *vec[node]) {
            fre[lvl[x]]--;
        }
    }
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i < n ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }

    dfs1(1 , -1 , 0);
    dfs2(1 , -1 , 1);

    for(int i =1 ; i <= n ; i++ ) {
        cout<<anslvl[i]-lvl[i]<<'\n';
    }
    return 0;
}
