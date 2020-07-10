#include<bits/stdc++.h>
#define ll		long long int
#define fastio	ios::sync_with_stdio(0);
using namespace std;

const int N = 5005;
const ll MOD = 1e9 + 7;

ll dp[N][2];
int ok[N][N], mn[N], mx[N];

int main()
{
	fastio;
	ll n, a , b , k;
	cin>>n>>a>>b>>k;

	for(int i =1 ; i <=n ; i++ ) mx[i] = mn[i] = i;

	for(int i =1 ; i <= n ; i++ ) {
		for(int j = 1 ; j <= n ; j++ ) {

			if( abs(i-j) < abs(i-b) && (i != j) ) {
				
				mx[j] = max(mx[j], i);
				mn[j] = min(mn[j], i);
				ok[i][j] = 1;
			}
		}
	}
	
	// for(int i =1 ; i <=n ; i++ ) cout<<i<<" -> "<<mn[i]<<" - "<<mx[i]<<'\n';

	for(int i =1 ; i <=n ; i++ ) {
		if(ok[a][i] ) dp[i][1] = 1;
	}

	// cout<<'\n';
	// for(int i =1 ; i <=n ; i++ ) cout<<dp[i][1]<<" ";
	// cout<<'\n';

	for(int i =1 ; i <= n ; i++ ) dp[i][1] += dp[i-1][1];


	for(int i =2 ; i <= k ; i++ ) {
		int ii = i%2;

		for(int j = 1; j <=n ; j++ ) {
			int frm = mn[j];
			int to = mx[j];
			ll tmp1 = (dp[to][ii^1] - dp[frm-1][ ii ^ 1 ] + MOD) % MOD;
			ll tmp2 = (dp[j][ ii ^ 1] - dp[j-1][ ii ^ 1 ] + MOD) % MOD;
			// ll tmp2 = 0;
			dp[j][ ii ] = (dp[j][ ii ] + tmp1 - tmp2 + MOD) % MOD;
		}

		// for(int j =1 ; j <=n ; j++ ) cout<<dp[j][ii]<<" ";
		// cout<<'\n';

		for(int j =1 ; j <= n ; j++ ) {
			dp[j][ ii ] += dp[j-1][ ii ];
			dp[j][ ii ] %= MOD;
		}

		for(int j =1 ; j <= n ; j++) dp[j][ii^1] = 0;
	}
	
	cout<<dp[n][k%2]<<'\n';
	return 0;
}