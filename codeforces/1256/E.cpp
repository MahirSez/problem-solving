#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
ll dp[MAX]  , frm[MAX] , ans[MAX];
pll ara[MAX];
int main()
{
    fastRead;
    int n;
    cin>>n;
    for(int i = 1 ; i <=n ; i++ ) {
        cin>>ara[i].uu;
        ara[i].vv = i;
    }
    sort(ara +1,ara  + n + 1);
    

    
    for(int i =1 ; i<=n ; i++ ) dp[i] = INF;
    
    for(int i = 1 ;  i<=n ; i++) {
        
        
        if( i+2 <= n && dp[i+2] > ara[i+2].uu - ara[i].uu + dp[i-1] ) dp[i+2] = ara[i+2].uu - ara[i].uu + dp[i-1] , frm[i+2] = i;
        if( i+3 <= n && dp[i+3] > ara[i+3].uu - ara[i].uu + dp[i-1] ) dp[i+3] = ara[i+3].uu - ara[i].uu + dp[i-1] , frm[i+3] = i;
        if( i+4 <= n && dp[i+4] > ara[i+4].uu - ara[i].uu + dp[i-1] ) dp[i+4] = ara[i+4].uu - ara[i].uu + dp[i-1] , frm[i+4] = i;
        
    }
    
//    for(int i =1;  i <=n ; i++ ) cout<<ara[i].uu<<" "; cout<<'\n';
//    for(int i =1;  i <=n ; i++ ) cout<<dp[i]<<" "; cout<<'\n';
//    for(int i =1;  i <=n ; i++ ) cout<<frm[i]<<" "; cout<<'\n';
//    
    
    
    int now = n;
    
    int cnt = 0;
    while(now >=1 ) {
        
        cnt++;
        for(int i = frm[now] ; i <= now ; i++ ) ans[ara[i].vv] = cnt;
        now = frm[now]-1;
    }
    
    cout<<dp[n]<<" "<<cnt<<'\n';
    for(int i =1 ; i <=n ; i++ ) cout<<ans[i]<<" ";
    cout<<'\n';
    
    return 0;
}