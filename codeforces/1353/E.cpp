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
int dp[MAX][5] , vis[MAX][5];
int one = 0 , zero = 0;
int n , k;
string str;
int solve(int id , int state) {
    
    if(state > 2) return INF;
    if(id >= n ) return 0;
    
    if( vis[id][state] != 0) return dp[id][state];
    vis[id][state] = 1;
    
    int &ret = dp[id][state];
    ret = n;
    
    ret = min(ret , solve(id ,state + 1));
    
    if(str[id] == '0') {
        
        if(state == 0 || state == 2) ret = min(ret , solve(id+k , state));
        else ret = min(ret , solve(id+k , state) +1);
    }
    else {
        
        if(state == 0 || state == 2) ret = min(ret , solve(id+k , state));
        else ret = min(ret , solve(id+k , state) -1);
        
    }
    
    return ret;
    
    
}
/*
1
13 1
0000010000000
*/

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        

        cin>>n>>k;
        
        cin>>str;
        
        one = zero = 0;
        
        for(int i =0 ; i <=n ; i++ ) {
            for(int j =0 ; j <=2 ; j++ ) {
                vis[i][j] = 0;
            }
        }
        
        for(int i =0 ; i < n ; i++) {
            char x = str[i];
            if(x == '0') zero++;
            else {
                one++;
            }
        }

        int ans = n;
        
        for(int i =0 ; i < k ; i++ ) ans = min(ans , one+ solve(i , 0));
        cout<<ans<<'\n';
    }
    return 0;
}