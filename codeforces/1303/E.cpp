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

string s , t;
int n , m , dp[401][401][401];

int part ;

int solve(int id , int id1 , int id2) {
    
    if(id1 == part && id2 == m) return 0;
    if(id == n ) return -INF;
    
    int &ret = dp[id][id1][id2];
    if( ret != -1 ) return ret;
    
    ret = solve(id+1 , id1 , id2);
    
    if(id1 < part && s[id] == t[id1]) {
        
        ret = max(ret , 1 + solve(id+1 , id1+1 , id2));
    }
    
    if(id2 < m && s[id] == t[id2]) {
        
        ret = max(ret , 1 + solve(id+1 , id1 , id2 + 1));
    }
    
    return ret;
    
}


int main()
{
    fastRead;
    int tt;
    cin>>tt;
    while(tt--) {
        
        cin>>s>>t;
        
        n = s.size();
        m = t.size();
        for(int i = 0 ; i <=n ; i++ ) 
            for(int j =0 ; j <= m ; j++ ) 
                for(int k =0 ; k <= m ; k++ ) 
                    dp[i][j][k] = -1;
        
        bool ok = 0;
        
        for(int i = 0 ; i <= m ; i++ ) {
            
            part = i;
            int get = solve(0 , 0 , i );
            if(get == m ) ok = 1;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    return 0;
    
    
}