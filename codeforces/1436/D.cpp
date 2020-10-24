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

const int N = 1e6 + 6;

vector<int>edg[N];
ll ara[N];
ll sz[N], av[N] , mx[N];

void dfs(int node) {



    for(auto x : edg[node]) {
        dfs(x);
        sz[node] += sz[x];
        mx[node] = max(mx[node] , mx[x]);
    }

    if(sz[node] == 0) {
        sz[node] = 1;
        mx[node] = ara[node];
        av[node] = 0;
        return ;
    }
    

    for(auto x : edg[node]) {
        av[node] += (mx[node] - mx[x]) * sz[x] + av[x];
    }



    if(ara[node] <= av[node]) {
        av[node] -= ara[node];
    }
    else {
        assert(ara[node] > 0);

        ara[node] -= av[node];

        mx[node] += (ara[node]-1)/sz[node] + 1;

        ll tmp = ara[node] % sz[node];

        if(tmp) av[node] = sz[node] - tmp;
        else av[node] = 0;
    }

    
}


int main() {
    fastio;

    int n;
    cin>>n;
    for(int i =2 ; i <= n ; i++ ) {
        int p;
        cin>>p;
        edg[p].push_back(i);
    }

    

    for(int i =1 ; i <=n ; i++ ) cin>>ara[i];


    dfs(1);

    // for(int i =1; i <=n ; i++ ) cout<<
    cout<<mx[1]<<'\n';
    return 0;


}