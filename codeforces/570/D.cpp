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
int n , m , lvl[MAX] , mxlvl[MAX] , sz[MAX] , mask[MAX] , ans[MAX];
vector<int>edg[MAX] ;
vector<pii> str[MAX];
string ss;

vector<int>*vec[MAX];

void dfs1(int node , int lev) {

    lvl[node] = lev;
    mxlvl[node] = lev;

    sz[node] = 1;
    for(auto x : edg[node]) {
        dfs1(x , lev+1);
        sz[node] += sz[x];
        mxlvl[node] = max(mxlvl[node] , mxlvl[x]);
    }
}

void dfs2(int node , int keep) {

    int bigChild = -1;
    for(auto x : edg[node]) {
		if(bigChild == -1 || sz[x] > sz[bigChild] ) bigChild = x;
    }

    for(auto x : edg[node]) {
		if( x == bigChild) continue;
        dfs2(x , 0);
    }

    if( bigChild == -1) {
        vec[node] = new vector<int>();
    }
    else {
		dfs2(bigChild , 1);

        vec[node] = vec[bigChild];
    }

    vec[node]->push_back(node);
    mask[lvl[node]] ^= (1<< (ss[node]-'a') ) ;

    for(auto x: edg[node]) {

        if(x == bigChild) continue;
        for(auto xx: *vec[x]) {
			vec[node]->push_back(xx);
			mask[lvl[xx]] ^= (1<<(ss[xx]-'a') );
        }
    }

    for(auto x : str[node]) {

        int lev = x.uu;
        int id = x.vv;

        if( lev < lvl[node] || lev > mxlvl[node] ) {
			ans[id] = 1;
			continue;
        }

        ans[id] = (__builtin_popcount(mask[lev]) <=1 );
    }
    if( keep ==0) {

        for(auto x : *vec[node]) {
			mask[lvl[x]] ^= (1<<ss[x]-'a');
        }
    }

}


int main()
{
    fastRead;
    cin>>n>>m;

    for(int i = 2 ; i <= n ; i++ ) {
		int par;
		cin>>par;
        edg[par].push_back(i);
    }
    cin>>ss;
    ss = '*' + ss;
    dfs1(1, 1);
//	for(int i =1 ; i <= n ; i++ ) {
//		cout<<sz[i]<<" ";
//	}
//	cout<<endl;

	for(int i = 1 ; i<= m ; i++ ) {

        int v , h;
        cin>>v>>h;
        str[v].push_back({h,i});
    }
    dfs2(1, 0);



	for(int i =1 ; i <= m ; i++ ) {
		if( ans[i]) cout<<"Yes\n";
		else cout<<"No\n";
	}
	cout<<'\n';
	return 0;
}
