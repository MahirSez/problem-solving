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
int n , mark[MAX] , ara[MAX];
vector<int>prm , vec[MAX] , edg[MAX];

map<int,int>mp[MAX];
int ans ;

void seive() {

    for(ll i =2 ; i * i < MAX ; i++ ) {
        
        if(mark[i]) continue;
        
        for(int j = i*i ; j < MAX  ; j+= i ) mark[j] = 1;
    }
    
    for(int i =2 ; i < MAX ; i++ ) {
        
        if(mark[i] == 0 ) prm.push_back(i);
    }
    
    for(auto x : prm ) {
        
        for(int j = x ; j<MAX ; j += x) vec[j].push_back(x);
    }
}


void dfs(int node , int p ) {
    
    
    for(auto x : edg[node]) {
        if(x == p ) continue;
        dfs(x , node);
    }
    
    
    for(auto x : vec[ ara[node] ] ) {
        
        
        int mx1 = 0;
        int mx2 = 0;
        
        mp[node][x] = 1;
        
        for(auto xx : edg[node]) {
            
            if(xx == p ) continue;
            
            
            mp[node][x] = max(mp[node][x] , mp[xx][x] + 1);
            
            if(mp[xx][x] >= mx1) {
                mx2 = mx1;
                mx1 = mp[xx][x];
            }
            else if(mp[xx][x] >= mx2) mx2 = mp[xx][x] ;
        }
        
        ans = max(ans ,1+ mx1 + mx2 );
        
    }
    
    
    
    
}


int main()
{
    fastRead;
    seive();
    
    cin>>n;
    
    for(int i = 1 ; i <=n ; i++ ) cin>>ara[i];
    
    for(int i =1 ; i < n ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    dfs(1 , -1);
    
//    for(int i =1 ; i <= n ; i++ ) {
//        
//        cout<<i<<" "<<ara[i]<<"  -> \n";
//        for(auto x : vec[ara[i] ]) cout<<x<<" = "<<mp[i][x]<<'\n';
//        cout<<'\n';
//    }
    
    cout<<ans<<'\n';
    return 0;
    
    
}