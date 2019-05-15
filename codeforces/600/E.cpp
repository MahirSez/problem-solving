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
int n , col[MAX] ,sz[MAX] ,cnt[MAX] , fre[MAX];
ll  ans[MAX] ;
vector<int>edg[MAX] , *vec[MAX];


void dfs1(int node ,int par) {

    sz[node] = 1;
    for(auto x : edg[node]) {
        if( x== par) continue;
        dfs1(x , node);
        sz[node] += sz[x];
    }
}


void dfs2(int node , int par , int keep) {

    int bigChild = -1;

    for(auto x : edg[node]) {

        if(x == par) continue;
        if( bigChild == -1 || sz[x] > sz[bigChild] ) bigChild = x;
    }

    for(auto x: edg[node] ) {
		if( x == bigChild || x == par ) continue;
        dfs2(x , node, 0 );
    }




    if(bigChild ==-1) vec[node] = new vector<int>();
    else {

		dfs2(bigChild , node , 1);
		vec[node] = vec[bigChild];
        ans[node] = ans[bigChild];
        fre[node] = fre[bigChild];
    }

    vec[node]->push_back(node);

    cnt[col[node]]++;

    if( cnt[col[node]] > fre[node]) {
        ans[node] = col[node];
		fre[node] = cnt[col[node]] ;
    }
    else if( cnt[col[node]] == fre[node] ) {
        ans[node] += col[node];
    }

    for(auto x : edg[node]) {
		if( x == par || x == bigChild ) continue;

        for(auto xx : *vec[x] ) {

            cnt[col[xx]]++;
            vec[node]->push_back(xx);

			if( cnt[col[xx]] > fre[node]) {
				ans[node] = col[xx];
				fre[node] = cnt[col[xx]];
			}
			else if( cnt[col[xx]] == fre[node] ) {
				ans[node] += col[xx];
			}

        }
    }

    if( keep ==0 ) {

        for(auto x : *vec[node]) {
            cnt[col[x]]--;
        }
    }

}



int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i<= n; i++) cin>>col[i];

    for(int i =1 ; i < n ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }

    dfs1(1 , -1);

    dfs2(1 , -1 , 1);

    for(int i =1 ; i<= n ; i++ ) cout<<ans[i]<<" ";
    cout<<endl;
}
