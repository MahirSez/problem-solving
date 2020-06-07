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

int n , m;

int Gcnt , Bcnt;

int ara[60][60], dist[60][60];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


bool safe(int x, int y) {
        
    for(int i =0 ; i < 4; i ++ ) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx>=0 && xx< n && yy>=0 && yy<m && ara[xx][yy] == -5) return 0;
    }
    return 1;
}



bool bfs() {
    
    
    if(ara[n-1][m-1] == -5) return 0;

    if(!safe(n-1,m-1)) {
        return (Gcnt == 0);
    }
    
    memset(dist, 0, sizeof dist);
    
    queue<pii>q;
    q.push({n-1, m-1});
    
    dist[n-1][m-1] = 1;
    
    while(!q.empty()) {
        
        int tx = q.front().uu;
        int ty = q.front().vv;
        q.pop();
        
        for(int i = 0 ; i < 4; i++ ) {
            int xx = tx + dx[i];
            int yy = ty + dy[i];
            
            if(xx>= n || xx < 0 || yy >= m || yy < 0 )continue;
            if(ara[xx][yy] < 0) continue;
            if(dist[xx][yy] ) continue;
            
            
            if(!safe(xx,yy)) {
                dist[xx][yy] = -1;
                continue;
            }
            
            dist[xx][yy] = 1;
            q.push({xx,yy});
        }
    }
    
    for(int i =0 ; i< n; i++)  {
        for(int j =0 ; j <m ;j++ ) {
            if(ara[i][j] == 5 && dist[i][j] != 1) return 0;
        }
    }
    return 1;
    
}



int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        cin>>n>>m;
        Gcnt = 0 , Bcnt = 0;
        
        for(int i =0 ; i < n ; i++ ) {
            string str;
            cin>>str;
            for(int j =0 ; j < m ; j++ ){
                if(str[j] == 'G') ara[i][j] = 5, Gcnt++;
                else if(str[j] == 'B') ara[i][j] = -5, Bcnt++;
                else if(str[j] == '#') ara[i][j] = -1;
                else ara[i][j] = 0;
            }
        }
        bool ok = bfs();
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}