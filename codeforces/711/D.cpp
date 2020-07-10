#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int N = 2e5 + 5;
const ll MOD = 1e9 + 7;
int to[N], vis[N], lvl[N];

ll bigMod(ll a, ll b) {

	if( b == 0 ) return 1LL;
	ll ret = bigMod(a, b/2);
	ret = (ret * ret) % MOD;
	if(b & 1) ret = (ret*a)%MOD;
	return ret;
}

int go(int x, int l) {

	vis[x] = 1;
	lvl[x] = l;
	int ret = 0;
	if( vis[to[x]] == 1) ret =  l - lvl[to[x]] + 1;
	else if( vis[to[x]] == 0) ret = go(to[x], l + 1);
	vis[x] = 2;
	return ret;
}

int main()
{
    fastRead;
    int n;
	cin>>n;
	for(int i =1 ; i <=n ; i++) cin>>to[i];

	int tot = n;
	ll ans = 1;

	for(int i =1 ; i <=n ; i++ ) {
		if(vis[i]) continue;
		int ret = go(i, 1);
		tot -= ret;
		if(ret ) {
			ll tmp = bigMod(2, ret);
			tmp = (tmp - 2 + MOD) %MOD;
			ans = (ans * tmp)%MOD;
		}
	}
	ans = (ans * bigMod(2, tot))%MOD;
	cout<<ans<<'\n';
	return 0;
}