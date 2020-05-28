#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e3 + 3;
int n , m , t;
int ara[MAX][MAX] , id[MAX][MAX] , taken[MAX][MAX] , col[MAX*MAX];
ll dst[MAX][MAX];
int compCnt ;

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0 };

void go(int x , int y ) {
    
    queue<pii>q;
    q.push({x,y});
    
    vector<pii>vec;
    taken[x][y] = 1;
    
    while(!q.empty()) {
        
        int tx = q.front().uu;
        int ty = q.front().vv;
        vec.push_back({tx,ty});
        q.pop();
        
        for(int i =0 ; i<4 ; i++ ) {
            int xx = tx + dx[i];
            int yy = ty + dy[i];
            if(xx >=0 && xx < n && yy>=0 && yy < m && taken[xx][yy] == 0 && ara[xx][yy] == ara[x][y]) {
                taken[xx][yy] = 1;
                q.push({xx,yy});
            }
        }
    }
    
    if(vec.size() == 1) return;
    compCnt++;
    for(auto x : vec) {
        id[x.uu][x.vv] = compCnt;
    }
}


void precal() {
    
    deque<pii>dq;
    
    for(int i =0 ; i < n ; i++ ) {
        for(int j =0 ; j < m ;j++ ) {
            if(id[i][j]) dq.push_back({i,j});
        }
    }
    
    while(!dq.empty()) {
        
        int tx = dq.front().uu;
        int ty = dq.front().vv;
        dq.pop_front();
        
        for(int i =0 ; i < 4 ; i++ ) {
            int xx = tx + dx[i];
            int yy = ty + dy[i];
            if(xx >=0 && xx < n && yy >= 0 && yy < m && id[xx][yy] == 0 ) {
                dst[xx][yy] = dst[tx][ty] + 1;
                id[xx][yy] = id[tx][ty];
                dq.push_back({xx,yy});
            }
        }
    }
}


int main()
{
    fastRead;
    cin>>n>>m>>t;
    for(int i =0 ; i < n ; i++) {
        string str;
        cin>>str;
        for(int j =0 ; j < m ;j++ ) {
            ara[i][j] = str[j]-'0';
        }
    }
    
    
    for(int i =0 ; i < n ; i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            if(taken[i][j]) continue;
            go(i,j);
        }
    }    
    
    for(int i =0 ; i < n ; i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            if(id[i][j] == 0 ) continue;
            col[ id[i][j] ] = ara[i][j];
        }
    }
    
    precal();
    
    
//    for(int i =0 ; i < n ; i++ ) {
//        for(int j = 0 ; j < m ; j++ ) {
//            cout<<id[i][j];
//        }
//        cout<<'\n';
//    }
//    cout<<'\n';
//    for(int i =0 ; i < n ; i++ ) {
//        for(int j = 0 ; j < m ; j++ ) {
//            cout<<dst[i][j];
//        }
//        cout<<'\n';
//    }
//    cout<<'\n';

    while(t--) {
        
        ll x , y , p;
        cin>>x>>y>>p;
        x-- , y--;
        if(id[x][y] == 0 || p <= dst[x][y]) cout<<ara[x][y]<<'\n';
        else cout<<(col[id[x][y]]^(p%2))<<'\n';
    }
    
    return 0;
    
}