#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e3 + 6;
int ara[MAX][MAX];
int dx[] = { 0 , 0 , 1 , -1};
int dy[] = { 1 ,-1 , 0 , 0};
int n , m;

void bfs(int r , int c) {

    
    queue<pii>q;
    
    ara[r][c] = -1;
    
    q.push({r,c});
    
    while(!q.empty()) {
        
        int tr = q.front().uu;
        int tc = q.front().vv;
        q.pop();
        
        
        for(int i = 0 ; i < 4; i++ ) {
            
            int rr = tr + dx[i];
            int cc = tc + dy[i];
            
            if(rr >=0 && rr < n && cc >=0 && cc < m && ara[rr][cc] == 1) {
                
                ara[rr][cc] = -1;
                q.push({rr,cc});
            }
        }
    }
    
}

int main()
{
    fastRead;
    
    
    cin>>n>>m;
    int cnt = 0;
    
    
    for(int i =0 ; i <n ; i++ ) {
        string s;
        cin>>s;
        for(int j =0 ; j < m ; j++ ) {
            if(s[j] == '#') {
                ara[i][j] = 1;
                cnt++;
            }
        }
    }
    
    bool ok = 1;
    
    int roEmpty = 0 , colEmpty = 0;
    
    for(int i = 0 ; i <n ; i++ ) {
        
        int id1 =-1, id2 = -1;
        
        for(int j = 0 ; j < m ; j++ ) if( ara[i][j] ) id2 = j;
        for(int j = m-1 ; j >=0 ; j-- ) if( ara[i][j] ) id1 = j;
        
        if(id1 == -1) {
            roEmpty = 1;
            continue;
        }
        
        for(int j = id1 + 1 ; j < id2 ; j++ ) {
            
            if(ara[i][j] == 0) ok = 0;
        }
        
    }
    
    for(int j =0  ; j < m ; j++ ) {
        int id1 =-1, id2 = -1;
        
        for(int i = 0; i < n ; i++ ) if(ara[i][j]) id2 = i;
        for(int i = n-1 ; i >= 0 ; i--) if(ara[i][j] ) id1 = i;
        
        if(id1 == -1) {
            colEmpty = 1;
            continue;
        }
        
        for(int i = id1+1 ; i < id2 ; i++ ) {
            if(ara[i][j] == 0 ) ok = 0;
        }
    }
    if(roEmpty^colEmpty ) ok = 0;
    
    if(!ok) {
        cout<<-1<<'\n';
        return 0;
    }
    
    int ans = 0;
    
    for(int i = 0 ; i < n ; i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            if(ara[i][j] != 1 ) continue;
            
            bfs(i , j);
            ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}