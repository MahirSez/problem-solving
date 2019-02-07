#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e18
#define EPS     	1e-8
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m , k;

ll nxt[MAX] , val[MAX] , dp[100005][300];
vector<int>st[MAX] , ed[MAX];
int s[MAX] , t[MAX] , d[MAX] ,w[MAX];

ll solve(int id , int taken)  {

	if( id > n ) {
		return 0;
	}
	
	ll &ret = dp[id][taken];
	if( ret != -1) return ret;

	ret = solve(nxt[id]+1 , taken) + val[id];
	if( taken >0)ret = min(ret , solve(id +1, taken - 1 ) );
	return ret;
}

multiset<pii>mst;

int main() {
	fastRead;
	cin>>n>>m>>k;
	
	for(int i =0 ; i < k ; i++ ) {
		cin>>s[i]>>t[i]>>d[i]>>w[i];
		st[s[i]].push_back(i);
		ed[t[i]].push_back(i);
	}
	for(int i =1 ; i<= n ; i++ ) {
		nxt[i] = i;

		for(auto x : st[i]) {
			mst.insert({w[x] , d[x]});
		}

		if( !mst.empty() ) {

			auto id = mst.end();
			id--;
			nxt[i] = id->vv;
			val[i] = id->uu;
		}
		for(int x : ed[i]) {
			mst.erase(mst.find(pii(w[x] , d[x] )) );
		}
	}
	
	memset(dp , -1 , sizeof dp);
	cout<<solve(1 , m )<<endl;
	return 0;
}