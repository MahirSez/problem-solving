#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0)
#define ll long long int
using namespace std;

const ll MOD = 1e9 + 7;
const int N = 1e5 + 5;

ll bigMod(ll a, ll b) {
	
	if( b == 0 ) return 1LL;
	ll ret = bigMod(a, b/2);
	ret = (ret * ret) %MOD;
	if(b & 1) ret = (ret * a) %MOD;
	return ret;
}
map<ll,ll>mp;
vector<ll> rec[N];

ll solve(ll x) {
	if(x == 1) return 1;
	if(mp.find(x) != mp.end()) return mp[x];

	ll ret = bigMod(2, x-1);
	ll rt = sqrt(x);

	vector<int>vec;
	for(int i =1 ; i <= rt + 10; i++ ) {
		if(x%i) continue;
		vec.push_back(x/i);
		vec.push_back(i);
	}
	sort(vec.begin(), vec.end());
	vec.erase( unique(vec.begin(), vec.end()) , vec.end() );

	for(int i = 1 ; i < vec.size() ; i++ ) {
		ll tmp = solve(x/vec[i]);
		ret = (ret - tmp + MOD)%MOD;
	}
	return mp[x] = ret;
}

int main()
{
    fastio;

	int x, y;
	cin>>x>>y;
	if(y % x) {
		cout<<0<<'\n';	
		return 0;
	}

	cout<<solve(y/x)<<'\n';

    return  0;
}