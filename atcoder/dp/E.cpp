#include<bits/stdc++.h>
#define MAX 100005
#define INF 2e9
#define ll long long int
#define fastRead ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
int n;
ll v[200] , w[200] ,dp[200][MAX] , W;

int main()
{
	fastRead;
	cin>>n>>W;

	ll tot = 0;
	for(int i =1 ; i<= n ; i++ ) cin>>w[i]>>v[i] , tot +=v[i];


	ll ans = 0;
    for(int i = 1 ; i<= tot ; i++ ) {

        dp[0][i] = INF;

        for(int j = 1 ; j <= n ; j++ )  {

            if( v[j] <= i ) {
				dp[j][i] = min(dp[j-1][i] , dp[j-1][i-v[j]]  + w[j]);
            }
            else dp[j][i] = dp[j-1][i];
        }
        if(	dp[n][i] <= W) ans = max(1LL*i  , ans);
    }

    cout<<ans<<endl;
    return 0;

}

