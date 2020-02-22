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
int dp[(1<<24)];
int main()
{
    fastRead;
    int n;
    cin>>n;
    for(int i= 0 ; i < n ; i++ ) {
        string s;
        cin>>s;
        int tmp = 0;
        for(int j =0 ; j < 3 ; j++ ) {
            tmp |= ( 1<< (s[j] -'a') );
        }
        dp[tmp]++;
    }
    
    for(int i = 0 ; i < 24 ; i++ ) {
        
        for(int mask = 0 ; mask < (1<<24) ; mask ++ ) {
            
            if(mask & (1<<i)) dp[mask] += dp[mask ^ (1<<i)];
        }
    }
    
    int ans = 0;
    
    for(int mask = 0 ; mask < (1<<24) ; mask++ ) {
        
        int tmp = ( (1<<24) - 1) ^ mask;
        
        int tgt = n - dp[tmp];
        ans ^= (tgt*tgt);
    }
    
    cout<<ans<<'\n';
    return 0;
    
}