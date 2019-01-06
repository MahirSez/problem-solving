#include<bits/stdc++.h>
#define MAX 100005
#define INF 2e9
#define ll long long int
#define fastRead ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
int n ,W;
ll v[200] , w[200] ,dp[200][MAX];

int main()
{
	fastRead;
	cin>>n>>W;

	for(int i =1 ; i<= n ; i++ ) cin>>w[i]>>v[i];

    for(int i = 1 ; i <= n ; i++ ) {

        for(int j =1 ; j <= W ; j++ ) {

            if(w[i] <= j ) {
                dp[i][j] = max(dp[i-1][j] , dp[i-1][j - w[i]]  + v[i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[n][W]<<endl;
    return 0;

}