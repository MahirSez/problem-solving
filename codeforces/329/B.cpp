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
int  n, m;
vector<pii>v;
int mx , my , fx , fy;
int ara[2000][2000];
int ase[MAX] , cnt;
int vis[2000][2000];
int dx[] = { 1 , -1 , 0 , 0};
int dy[] = { 0 , 0 , 1 , -1};


bool ok(int x , int y) {
    if( x >=0 && x < n && y>=0 && y < m && ara[x][y] == 0 && vis[x][y]==0  )
        return true;
    return false;
}


void bfs(int sx , int sy) {
    memset( vis , 0 , sizeof vis);
    vis[sx][sy] = 1;
    queue<pii>q;
    q.push({sx , sy});
    while( !q.empty() ) {

        int ax = q.front().uu;
        int ay = q.front().vv;
        int val = vis[ax][ay];
        q.pop();

        for(int i =0 ; i < 4 ; i++ ) {
            int tx = ax + dx[i];
            int ty = ay + dy[i];
            if( !ok(tx , ty) ) continue;

            vis[tx][ty] = val + 1;
            q.push({tx,ty});
        }
    }
}

int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < n ;i++ ) {
        string str;
        cin>>str;
        for(int j =0 ; j < m ;j++ ) {
            if( str[j] == 'S') {
                mx = i;
                my = j;
            }
            else if( str[j] == 'E') {
                fx = i;
                fy = j;
            }
            else if( str[j] == 'T') ara[i][j] = -1;
            else {
                int tmp = str[j] - '0';
                if( tmp ) {
                    v.push_back({i,j});
                    ase[cnt++] = tmp;
                }
            }
        }
    }
    bfs(fx , fy);
//    cout<<mx<<" "<<my<<" "<<fx<<" "<<fy<<endl;
    int tm = vis[mx][my];
    int ans = 0;
//    cout<<tm<<endl;
    for(int i =0 ; i < v.size() ; i++ ) {
        int x = v[i].uu;
        int y = v[i].vv;
//        cout<<x<<" "<<y<<" "<<vis[fx][fy]<<endl;
        if( vis[x][y] && vis[x][y] <= tm ) ans += ase[i];
    }
    cout<<ans<<endl;
    return 0;
}
