#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
ll cnt[2] , sub[MAX] , col[MAX];
vector<int>edg[MAX];

void dfs(int node , int par) {
    sub[node] =1;

    if( par== -1) col[node] =1;
    else col[node] = !col[par];

    cnt[col[node]]++;

    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if( x == par) continue;
        dfs(x , node);
        sub[node]  += sub[x];
    }
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n-1 ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    dfs(1 ,-1);
    ll tot = 0;
    for(int i = 1 ; i <= n ; i++ ) {
        tot += sub[i] *(n- sub[i]);
    }
    ll odd = cnt[0]* cnt[1];
    cout<<(tot+odd)/2LL<<endl;
    return 0;
}
