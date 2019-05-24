#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace std;
int n , sz[MAX] , ans[MAX];
ll val[MAX] , lvl[MAX] ;
vector<pll>edg[MAX];


typedef tree<
pll,
null_type,
less<pll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

ordered_set *ost[MAX];

void dfs1(int node , ll lev) {

    sz[node] = 1;
    lvl[node] = lev;
    for(auto x : edg[node]) {

        dfs1(x.uu , x.vv + lev);
        sz[node] += sz[x.uu];
    }
}

void dfs2(int node) {

    int big = -1;
    for(auto x : edg[node]) {
        dfs2(x.uu);
        if( big == -1 || sz[x.uu] > sz[big]) big = x.uu;
    }

    if( big == -1) ost[node] = new ordered_set();
    else ost[node] = ost[big];

    ans[node] = (*ost[node]).order_of_key({lvl[node] , INF});

    ost[node]->insert({lvl[node] - val[node] , node});

    for(auto x: edg[node]) {
        if( x.uu == big) continue;

        for(auto xx : *ost[x.uu] ) {

            ost[node]->insert(xx);
            if(lvl[xx.vv] - val[xx.vv] <= lvl[node]) ans[node]++;
        }
    }
}



int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i <=n ; i++ ) cin>>val[i];

    for(int i =2 ; i <= n ; i++ ) {
        int par , wt;
        cin>>par>>wt;
        edg[par].push_back({i, wt});
    }

    dfs1(1 , 0);
    dfs2(1 );

    for(int i =1 ; i<= n ; i++ ) cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
}
