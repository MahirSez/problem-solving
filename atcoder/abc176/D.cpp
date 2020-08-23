#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e3 + 6;

typedef tuple<int,int,int> tp;
int ara[N][N] , dist[N][N];
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

int n , m;

// int ddx[] = {-2 , -2, -2, -2, -2 , 2 ,2 ,2 ,2 , 2 , -1, -1, 0 , 0 , 1 ,1 ,   -1, -1, -1 , 0 , 0 , 1 , 1 ,1  };
// int ddy[] = {-2, -1 , 0 , 1 , 2 , -2 , -1 , 0 , 1 , 2 , 2 ,2 ,2 ,2 ,2 , 2 ,   -1 , 0 , 1 , 1 , -1 , -1 , 0 , 1 };

int ok(int x, int y) {
    return (x>=0 && x< n && y >=0 && y < m && ara[x][y] !=-1);
}

int main()  {
    fastio;
    
    int x1 , y1;
    int x2 , y2;
    cin>>n>>m>>x1>>y1>>x2>>y2;
    x1--,y1--,x2--,y2--;

    for(int i = 0 ; i < n ; i++ ) {
        string s;
        cin>>s;
        for(int j =0 ; j < m ; j++ ) {
            if(s[j] == '#') ara[i][j] = -1;
            dist[i][j] = INF;
        }
    }

    dist[x1][y1] = 0;
    priority_queue<tp, vector<tp> , greater<tp> >pq;

    pq.push({0 , x1 , y1});

    while(!pq.empty()) {
        int d , x , y;
        tie(d , x , y) = pq.top();
        pq.pop();

        if(d != dist[x][y]) continue;

        for(int i =0 ; i < 4 ; i++ ) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(ok(xx, yy) && dist[xx][yy] > d ) {
                dist[xx][yy] = d;
                pq.push({d , xx , yy});
            }
        }
        for(int ddx = -2 ; ddx <= 2 ; ddx ++) {
            for(int ddy = -2 ; ddy <=2 ; ddy ++) {
                int xx = x + ddx;
                int yy = y + ddy;
                if(ok(xx, yy) && dist[xx][yy] > d + 1) {
                    dist[xx][yy] = d+1;
                    pq.push({d+1 , xx , yy});
                }
            }
        }
\
    }
    if(dist[x2][y2] == INF) cout<<-1<<'\n';
    else cout<<dist[x2][y2]<<'\n';

    
    return 0;
    
}