#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
double dp[400][400][400];

int ara[4];

int main()
{
    fastRead;
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++ ) {
        int tmp;
        cin>>tmp;
        ara[tmp]++;
    }
    
    for(int i = 0 ;i <= ara[3] ; i++ ) {
        for(int j = 0 ; j <= ara[2]+ ara[3] - i ; j++ ) {
            for(int k =0 ; k <= ara[3] + ara[2] + ara[1] - i - j ; k++ ) {
                if(i == 0 && j ==0 && k==0) continue;
                
                if(i) dp[i][j][k] += 1.0*i*dp[i-1][j+1][k];
                if(j) dp[i][j][k] += 1.0*j*dp[i][j-1][k+1];
                if(k) dp[i][j][k] += 1.0*k*dp[i][j][k-1];
                
                dp[i][j][k] += n;
                dp[i][j][k] /= 1.0*(i+j+k);
            }
        }
    }
    cout<<setprecision(12)<<fixed<<dp[ara[3]][ara[2]][ara[1]]<<'\n';
    return 0;
    
}