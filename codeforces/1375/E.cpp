#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int N = 1e6 + 6;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

vector<int>rec[N];
/*
5
3 4 3 1 2
*/
int main()	{
	fastio;
	int n;
	cin>>n;
	vector<int>vec(n);
	vector<pii> ans, rec(n);

	for(int i =0 ; i < n ; i++ ) {
		cin>>rec[i].uu;
		rec[i].vv = i;
	}
	sort(rec.begin(), rec.end());
	int cnt = 0;

	for(auto x : rec) vec[x.vv] = ++cnt;
	// for(auto x: vec) cout<<x<<" ";
	// cout<<"\n\n";

	
	for(int i = n-1 ; i >=0; i--) {

		vector<pii>rec;

		for(int j = i-1; j >=0 ; j-- ) {
			
			if(vec[j] > vec[i]) rec.push_back({vec[j], j});
		}
		sort(rec.begin(), rec.end());
		for(auto x : rec) {
			int id = x.vv;
			ans.push_back({id, i});
			swap(vec[id], vec[i]);
		}

		// for(auto x : vec) cout<<x<<" ";
		// cout<<'\n';
	}

	
	for(int i =1 ; i < n ; i++ ) {
		assert(vec[i] >= vec[i-1]);
	}
	cout<<ans.size()<<'\n';
	for(auto x : ans) cout<<x.uu+1<<" "<<x.vv+1<<'\n';
	return 0;
}