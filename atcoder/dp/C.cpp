#include<bits/stdc++.h>
#define MAX 1000006
#define INF 2e9
using namespace std;
int a[MAX] , b[MAX] , c[MAX] , dp[MAX][4];
int main()
{
    int n;
    cin>>n;
    for(int i =0 ; i < n ; i++) cin>>a[i]>>b[i]>>c[i];

    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    for(int i =1 ; i < n ; i++ ) {

        for(int j = 0 ; j < 3 ; j++) {

            if(j != 0) dp[i][0] = max(dp[i-1][1] , dp[i-1][2]) + a[i];
            if(j != 1) dp[i][1] = max(dp[i-1][0] , dp[i-1][2]) + b[i];
            if(j != 2) dp[i][2] = max(dp[i-1][0] , dp[i-1][1]) + c[i];
        }
    }

    cout<<max(dp[n-1][0] , max(dp[n-1][1] , dp[n-1][2]))<<endl;
    return 0;
}

