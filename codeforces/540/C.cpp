#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m;
int ara[1000][1000] , vis[1000][1000];
int fx , fy , sx , sy;

int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};


bool ok(int x , int y) {

    if( x < n && x>=0 && y>=0 && y<m && ara[x][y]==0 && vis[x][y] ==0)
        return true;
    return false;
}

void bfs() {
    vis[sx][sy] = 1;
    queue<pii>q;
    q.push({sx,sy});
    while( !q.empty() ) {

        int ax = q.front().uu;
        int ay = q.front().vv;
//    cout<<"------>"<<ax<<" "<<ay<<endl;
        q.pop();

        for(int i =0 ; i < 4 ; i++ ) {
            int tx = ax + dx[i];
            int ty = ay + dy[i];
//            cout<<tx<<" ----- "<<ty<<endl;
            if( !ok(tx , ty)) continue;
            vis[tx][ty] = 1;
            q.push({tx,ty});
        }
    }
}


int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i< n ; i++ ) {
        string str;
        cin>>str;
        for(int j =0 ; j < m ; j++ ) {
            if( str[j] =='X') {
                ara[i][j] = -1;
            }
        }
    }
    cin>>sx>>sy>>fx>>fy;
    sx--;
    sy--;
    fx--;
    fy--;
    bfs();
//    for(int i =0 ; i < n ; i++ ) {
//        for(int j =0 ; j < m ; j++ ) {
//            cout<<vis[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    if( ara[fx][fy] == -1) {

        for(int i=0 ; i < 4 ; i++ ) {
            int ax = fx + dx[i];
            int ay = fy + dy[i];
            if( ax < n && ax>=0 && ay>=0 && ay<m && vis[ax][ay]) {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }

    if( vis[fx][fy] == 0 ) {
        cout<<"NO"<<endl;
        return 0;
    }
    int cnt = 0;
    for(int i=0 ; i < 4 ; i++ ) {
        int ax = fx + dx[i];
        int ay = fy + dy[i];
        if( ax < n && ax>=0 && ay>=0 && ay<m && vis[ax][ay]) {
            cnt++;
        }
    }

    if( cnt>=2 ) {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}
