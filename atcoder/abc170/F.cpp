#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define ppp         pair<pii,pii>
#define pppi        pair<ppp,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

int x1, yy1, x2, yy2;

int h, w, k;

vector< vector<int> > grid;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int solve() {
    
    if(x1==x2 && yy1 == yy2) return 0;
    
    int dist[h][w][4] , left[h][w][4];
    for(int i = 0 ; i < h ; i++ ) {
        for(int j =0 ; j <w ; j++ ) {
            for(int kk = 0 ; kk < 4; kk ++) {
                dist[i][j][kk] = INF;
                left[i][j][kk] = 0;
            }
        }
    }
    
    priority_queue<pppi> pq;
    
    for(int i =0; i < 4; i ++ ) {
        dist[x1][yy1][i] = 0;
        left[x1][yy1][i] = k;
        
        pq.push({{{0, k} ,{x1, yy1}}, i} );
    }
    
    
    while(!pq.empty()) {
        
        pppi top = pq.top();
        pq.pop();
        int topDst = -top.uu.uu.uu;
        int topLeft = top.uu.uu.vv;
        int tx = top.uu.vv.uu;
        int ty = top.uu.vv.vv;
        int topDir = top.vv;
        
        
        
        if(dist[tx][ty][topDir] < topDst) continue;
        if(left[tx][ty][topDir] > topLeft ) continue;
        
        for(int i =0 ; i < 4 ; i++ ) {
            
            int xx = tx + dx[i];
            int yy = ty + dy[i];
            if(xx < 0 || yy < 0 || xx >= h || yy >= w || grid[xx][yy] == -1) continue;
            
            int newDst = topDst;
            int newBaki = topLeft - 1;
            int newDir = i;
            
            if(newBaki == -1) {
                newDst++;
                newBaki = k-1;
            }
            
            if(newDir != topDir) {
                newDst = topDst + 1;
                newBaki = k-1;
            }
            if(topDst == 0 ) {
                newDst = 1;
                newBaki = k-1;
            }
            
            if(newDst < dist[xx][yy][newDir]) {
                dist[xx][yy][newDir] = newDst;
                left[xx][yy][newDir] = newBaki;
                
                pq.push({{{-newDst, newBaki}, {xx,yy}}, newDir});
            }
            else if(newDst == dist[xx][yy][newDir] && newBaki > left[xx][yy][newDir]) {
                left[xx][yy][newDir] = newBaki;
                pq.push({{{-newDst, newBaki}, {xx,yy}}, newDir});
            }
        }
    }
    
//    for(int i =0 ; i < h ; i++ ) {
//        for(int j = 0 ; j < w ; j++ ) {
//            int ret = INF;
//            for(int kk = 0 ; kk < 4 ; kk++ ) ret = min(ret, dist[i][j][kk]);
//            cout<<ret<<"\t";
//        }
//        cout<<'\n';
//    }
    int ret = INF;
    for(int i =0 ; i <4 ; i++ ) {
        ret = min(ret, dist[x2][yy2][i]);
    }
    return ret == INF? -1 : ret;
}

int main()
{
    fastRead;
    
    cin>>h>>w>>k;
    cin>>x1>>yy1>>x2>>yy2;
    x1--, yy1--, x2--, yy2--;
    
    for(int i =0 ; i < h ; i++ ) {
        string str;
        cin>>str;
        vector<int>tmp;
        for(auto x : str) {
            if(x == '.') tmp.push_back(0);
            else if(x == '@') tmp.push_back(-1);
        }
        grid.push_back(tmp);
    }
    
//    for(int i =0 ; i < h ; i++ ) {
//        for(int j =0 ; j < w ; j++ ) {
//            cout<<grid[i][j]<<" ";
//        }
//        cout<<'\n';
//    }

    cout<<solve()<<'\n';
    
    return 0;
    
    
}
