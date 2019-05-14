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
int n , col[MAX] , sz[MAX], mxCnt[MAX] , st[MAX] , fn[MAX] , _time , id[MAX] , cnt[MAX];
ll ans[MAX];
vector<int>edg[MAX];

void dfs1(int node , int par) {

	sz[node] = 1;
    st[node] = ++_time;
    id[_time] = node;

	for(auto x : edg[node]) {
		if( x== par) continue;
        dfs1(x , node);
        sz[node] += sz[x];
	}
	fn[node] = ++_time;
}

void dfs2(int node , int par, int keep) {

    int bigChild = -1;

    for(auto x : edg[node]) {

        if( x == par) continue;
        if( bigChild == -1 || sz[x] > sz[bigChild] ) bigChild = x;
    }


    for(auto x : edg[node]) {
        if( x == par || x == bigChild) continue;
        dfs2(x , node , 0);

    }

    if(bigChild != -1 ) {

        dfs2(bigChild , node , 1);
        mxCnt[node] = mxCnt[bigChild];
        ans[node] = ans[bigChild];
    }
    cnt[col[node]]++;

    if( cnt[col[node]] > mxCnt[node]) mxCnt[node] = cnt[col[node]] , ans[node] = col[node];
    else if( cnt[col[node]] == mxCnt[node] ) ans[node] += col[node];


    for(auto x : edg[node]) {
		if( x == par || x == bigChild ) continue;

        for(int i = st[x] ;  i<= fn[x] ; i++ ) {

            if( id[i] ==0 ) continue;
            int xx = id[i];

            cnt[col[xx]]++;

            if(cnt[col[xx]] > mxCnt[node]) mxCnt[node] = cnt[col[xx]] , ans[node] = col[xx];
            else if( cnt[col[xx]] == mxCnt[node] ) ans[node] += col[xx];
        }
    }

    if( keep == 0 ) {

        for(int i = st[node] ; i <= fn[node] ; i++ ) {
            if( id[i] ==0 ) continue;
            int xx = id[i];
            cnt[col[xx]]--;
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
    dfs2(1 , -1, 1);

    for(int i =1 ; i<= n ; i++ ) {
		cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
