#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int dp[(1<<22) + 22] , ara[MAX];
int main()
{
    fastRead;
    
    int n;
    cin>>n;
    memset(dp , - 1, sizeof dp);
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i];
        dp[ara[i]] = ara[i];
    }
    int till = 22;
    
    for(int i = 0 ; i <till ; i++ ) {
        
        for(int mask = 0 ; mask < (1<<till) ; mask++ ) {
            
            if( (mask & (1<<i) ) && dp[ (mask ^ (1<<i) ) ] != -1)  
                dp[mask] = dp[mask ^ (1<<i)];
        }
    }
    
    for(int i =0 ; i < n ; i++ ) {
        
        cout<<dp[ ((1<<till)-1) ^ ara[i] ]<<" ";
    }
    cout<<'\n';
    return 0;
    
}