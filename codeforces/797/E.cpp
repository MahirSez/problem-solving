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

const int MAX = 1e5 + 5;

const int magic = 320;


int dp[MAX][magic] , ara[MAX];

int main()
{
    fastRead;
    int n;
    cin>>n;
    
    for(int i =1 ; i <=n ; i++ ) {
        cin>>ara[i];
    }
    
    for(int i =1 ; i <=n ; i++ ) {
        
        for(int j = 1; j < magic ; j++ ) dp[i][j] = INF;
    }
    
    
    for(int i =n ; i >=1 ; i -- ) {
        
        for(int j = 1 ; j < magic ; j++ ) {
            
            if(i + ara[i] + j > n ) dp[i][j] = 1;
            else dp[i][j] = min(dp[i][j] , dp[ i + ara[i] + j][j] +1 );
        }
    }
    
//    for(int i =1 ; i <=n ; i++ ) cout<<dp[i][1]<<" ";
//    cout<<'\n';
    
    
    int q;
    cin>>q;
    while(q-- ) {
        int p , k;
        cin>>p>>k;
        if( k <magic ) {
            cout<<dp[p][k]<<'\n';
            continue;
        }
        
        int now = p;
        int cnt = 0;
        
        while(now <= n ) {
            now = now + ara[now] + k;
            cnt++;
        }
        
        cout<<cnt<<'\n';
            
    }
    return 0;
    
}