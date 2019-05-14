#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , col[MAX] , sz[MAX], mxCnt[MAX] ;
ll ans[MAX];
map<int,int>*mp[MAX];
vector<int>edg[MAX];

void dfs1(int node , int par) {

	sz[node] = 1;
	for(auto x : edg[node]) {
		if( x== par) continue;
        dfs1(x , node);
        sz[node] += sz[x];
	}
}

void dfs2(int node , int par) {

    int bigChild = -1;

    for(auto x: edg[node]) {
        if( x== par) continue;
        dfs2(x , node);
        if( bigChild == -1 || sz[x] > sz[bigChild]) bigChild = x;
    }

    if( bigChild == -1 ) mp[node] = new map<int,int>;
    else {
		mp[node] = mp[bigChild];
        ans[node] = ans[bigChild];
        mxCnt[node] = mxCnt[bigChild];
    }

    (*mp[node])[ col[node] ]++;

    int cnt = (*mp[node])[col[node]];

    if(cnt > mxCnt[node]) {
		mxCnt[node] = cnt;
        ans[node] = col[node];
    }
    else if( cnt == mxCnt[node]) {
		ans[node] += col[node];
    }
    for(auto x: edg[node]) {

        if( x== par || x == bigChild) continue;

        for(auto xx : *mp[x]) {

            (*mp[node])[xx.uu] += xx.vv;
            int cnt = ((*mp[node])[xx.uu]);

            if( cnt > mxCnt[node])  mxCnt[node] = cnt , ans[node] = xx.uu;
            else if( cnt == mxCnt[node]) ans[node] += xx.uu;
        }

    }
}

int main()
{
	fastRead;
	cin>>n;
	for(int i = 1 ; i <= n ; i++ ) cin>>col[i];
	for(int i =1 ; i< n ; i++ ) {
		int u , v;
		cin>>u>>v;
		edg[u].push_back(v);
		edg[v].push_back(u);
	}
    dfs1(1 , -1);
    dfs2(1 , -1);

    for(int i =1 ; i<= n ; i++ ) {
		cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
