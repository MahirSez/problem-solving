#include<bits/stdc++.h>
#define MAX 1000006
#define INF 2e9
using namespace std;
int ara[MAX] , dp[MAX];

int main()
{
    int n , k;
    cin>>n >> k;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];

	for(int i =1 ; i < n ; i++ ) {

        int val = INF;
        for(int j = 1 ; j <= k ; j++ ) {

			if( i - j < 0 ) continue;
            val = min(val , abs(ara[i] - ara[i-j]) + dp[i-j] );
        }
        dp[i] = val;
	}
	cout<<dp[n-1]<<endl;
	return 0;

}
