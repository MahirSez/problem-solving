#include<bits/stdc++.h>
#define MAX 1000006
#define INF 2e9
using namespace std;
int ara[MAX] , dp[MAX];

int main()
{
    int n;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];

	for(int i =1 ; i < n ; i++ ) {

        int val = INF;
        if( i-1 >=0 ) val = min(val ,abs(ara[i] - ara[i-1]) + dp[i-1]);
        if( i-2 >=0 ) val = min(val ,abs(ara[i] - ara[i-2]) +dp[i-2]);
        dp[i] = val;
	}
	cout<<dp[n-1]<<endl;
	return 0;

}
