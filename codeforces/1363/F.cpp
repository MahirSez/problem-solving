#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 3e3 + 3;

int fre1[MAX][30], fre2[MAX][30], dp[MAX][MAX];


/*
1
3
abc
cab
*/


int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n;
        cin>>n;
        string s1, s2;
        cin>>s2>>s1;
        string ss1 = s1 , ss2 = s2;
        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        if(ss1 != ss2) {
            cout<<-1<<'\n';
            continue;
        }
        s1 = "*" + s1;
        s2 = "*" + s2;
        
        for(int i = 0 ; i < 26 ; i++ ) {
            
            for(int j = 0 ; j <= n+1 ; j++ ) fre1[j][i] = fre2[j][i] = 0;
            
            for(int j = n ; j >=1 ; j--) {
                
                if(s1[j]-'a' == i) fre1[j][i]++;
                if(s2[j]-'a' == i) fre2[j][i]++;
                fre1[j][i] += fre1[j+1][i];
                fre2[j][i] += fre2[j+1][i];
            }
        }
        
        for(int i =0 ; i <=n ; i++ ) {
            for(int j =0 ; j <=n ; j++) dp[i][j] = 0;
        }
        
        for(int i =1 ; i <=n ; i++ ) {
            for(int j = 1 ;j <=n ; j++ ) {
                dp[i][j] = 1 + dp[i][j-1];
                
                if(s1[i] == s2[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                
                if( fre1[ i ][ s1[i]-'a' ] <= fre2[ j+1 ][ s1[i]-'a' ] ) {
                    
                    dp[i][j] = min(dp[i][j] , dp[i-1][j]);
                }
            }
        }
        
//        for(int i =0 ; i <=n ; i++ ) {
//            for(int j =0 ; j<=n ; j++ ) {
//                cout<<i<<" "<<j<<" --> "<<dp[i][j]<<'\n';
//            }
//        }
//        
        cout<<dp[n][n]<<'\n';
    }
    return 0;
}