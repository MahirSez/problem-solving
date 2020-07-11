#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int N = 2e5 + 6;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

ll sum[N][2], ara[N];
/*
5
1 2 3 4 5
*/


int main()
{
    fastio;
	int n;
	cin>>n;

	for(int i =1 ; i <=n ; i++ ) cin>>ara[i];

	for(int i = 1; i <=n ; i++ ) {
		if(i%2) {
			sum[i][1] = sum[i-1][1] + ara[i];
			sum[i][0] = sum[i-1][0];
		}
		else {
			sum[i][0] = sum[i-1][0] + ara[i];
			sum[i][1] = sum[i-1][1];
		}
	}

	// for(int i =1 ; i <=n ; i++ )cout<<sum[i][1]<<" ";
	// cout<<'\n';
	// for(int i =1 ; i <=n ; i++ )cout<<sum[i][0]<<" ";
	// cout<<'\n';
	//
	ll ans = sum[n][1];

	for(int i = 1 ; i <n ; i++ ) {

		ll tmp = sum[i][i%2] + sum[n][(i%2)^1] - sum[i][(i%2)^1];
		ans = max(ans, tmp);
	}
	cout<<ans<<'\n';
	return 0;
}