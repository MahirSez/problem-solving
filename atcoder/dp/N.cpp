#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll dp[500][500];

int main()
{
    fastRead;
    int n;
    cin>>n;
    vector<ll>vec(n+1), sum(n+1);
    for(int i =1 ; i <=n; i++ ) cin>>vec[i], sum[i] = (sum[i-1]+ vec[i]);
    
    for(int i = 1; i <=n ; i++ ) {
        for(int j =1 ; j <=n ; j++ ) dp[i][j] = INF;
    }
    
    for(int i =1 ; i <=n ; i++ ) dp[1][i] = vec[i];
    
    
    for(int i = 2; i <=n ; i++ ) {
        for(int j = 1; j + i - 1 <=n ; j++ ) {
            for(int k = 1; k < i ; k++ ) {
                
                int len1 = k, len2 = i - k;
                int frm1 = j ,frm2 = j + len1;
                
                int to = j + i -1;
                
//                cout<<i<<" -> "<<j<<" "<<i + j-1<<" -- "<<frm1<<" "<<frm1 + len1-1<<" -- "<<frm2<<" "<<len2 + frm2-1;
//                cout<<"\t--"<<dp[len1][frm1]<<" "<<dp[len2][frm2]<<" "<<sum[to] - sum[frm1-1]<<'\n';
                
                dp[i][j] = min(dp[i][j], dp[len1][frm1] + dp[len2][frm2] + sum[to] - sum[frm1-1]);
            }
        }
    }
    cout<<dp[n][1] - sum[n]<<'\n';
    return 0;
}