#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int board[20][20] ,ara[200] ,in[20][200] , to[200];
double dp[200][2];

int main()
{
    fastRead;
    int node = 100;
    int n = 10;
    
    for(int i = 0 ; i < 10 ; i++ ) {
        
        if(i%2 == 0) {
            for(int j = 0 ; j < 10 ; j++ ) board[i][j] = node--;
            continue;
        }
        
        for(int j = 9 ; j >=0 ; j--) board[i][j] = node--;
    }
    
//    for(int i =0 ; i < n ; i++ ) {
//        for(int j =0 ; j < n ; j++ ) cout<<board[i][j]<<" ";
//        cout<<'\n';
//    }
    
    memset(to , 0 , sizeof to);
    
    for(int i =0 ; i < 10 ; i++ ) {
        for(int j =0 ; j < 10 ; j++ ) {
            cin>>in[i][j];
            if(in[i][j] == 0) continue;
            
            
            int node1 = board[i][j];
            
            int node2 = board[i-in[i][j]][j];
            to[node1] = node2;
            
//            cout<<i<<" "<<j<<" "<<node1<<" -> "<<i-in[i][j]<<" "<<j<<" "<<node2<<'\n';
        }
    }
    

    
    for(int i = 99 ; i >= 1 ; i-- ) {
        
        int x = min(6 , 100 - i);
        
        dp[i][0] =6;
        for(int j = 1 ; j <= x ; j++ ) dp[i][0] += dp[i+j][1];
        dp[i][0] /=x;
        
        dp[i][1] = dp[i][0];
        
        if(to[i]) dp[i][1] = min(dp[i][1] , dp[to[i]][0]);
        
//        cout<<i<<" "<<x<<" "<<dp[i]<<'\n';
        
    }
    assert(dp[1][1] == dp[1][0]);
    cout<<setprecision(10)<<fixed<<dp[1][1]<<'\n';
    
    
    
    return 0;
}