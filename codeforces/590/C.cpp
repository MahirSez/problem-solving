#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int >
#define INF     	1e8
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m ;
string s;
int ara[1003][1003] , dst[4][1003][1003] , str[4][4];
int dx[] = {0 ,0 , 1 , -1};
int dy[] = {1 ,-1 , 0 , 0};

bool ok(int x, int y) {
    return (x>=1 && x<=n && y >= 1 && y<=m && ara[x][y] != -1);
}

void bfs(int col) {
    queue<pii>q;
    for(int i = 1 ; i <= n ;i++ ) {
        for(int j =1 ; j <= m ;j++ ) {
            if( ara[i][j] ==col ) {
                dst[col][i][j] = 0;
                q.push({i,j});
            }
        }
    }
    while( !q.empty() ) {
        int tx = q.front().uu;
        int ty = q.front().vv;
        q.pop();
        for(int i =0 ;  i < 4 ; i++ ) {
            int cx = tx + dx[i];
            int cy = ty + dy[i];
            if( !ok(cx,cy) || dst[col][cx][cy] != -1 ) continue;
            dst[col][cx][cy] = dst[col][tx][ty] + 1;
            if( ara[cx][cy] && ara[cx][cy] != col) {
                str[col][ara[cx][cy]] = min(str[col][ara[cx][cy]] ,dst[col][cx][cy]);
                str[ara[cx][cy]][col] = min(str[ara[cx][cy]][col] ,dst[col][cx][cy]);
            }
            q.push({cx,cy});
        }
    }
}

int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =1 ; i <= n ; i++ ) {
        cin>>s;
        s = '*' + s;
        for(int j =1 ; j <= m ; j++ ) {
            if( s[j] == '1') ara[i][j] = 1;
            else if( s[j] == '2') ara[i][j] = 2;
            else if( s[j] == '3') ara[i][j] = 3;
            else if( s[j] == '.') ara[i][j] = 0;
            else ara[i][j] = -1;
        }
    }
    memset( dst , -1 , sizeof dst);
    for(int i =1  ;i <=3 ; i++ ) {
        for(int j =1 ; j <=3 ; j++ ) {
            str[i][j] = INF;
        }
    }
    bfs(1);
    bfs(2);
    bfs(3);

    if( str[1][2] == INF || str[2][3] == INF || str[3][1] == INF) {
        cout<<-1<<endl;
        return 0;
    }

    int ans = INF;
    ans = min( ans , str[1][2] + str[2][3]);
    ans = min( ans , str[1][2] + str[1][3]);
    ans = min( ans , str[2][3] + str[1][3]);
    for(int i = 1 ;i<=n ; i++ ) {
        for(int j=1 ; j<=m ; j++ ) {
            if( dst[1][i][j] != -1 && dst[2][i][j] != -1 && dst[3][i][j] != -1) {
                ans = min( ans , dst[1][i][j] + dst[2][i][j] + dst[3][i][j] );
            }
        }
    }
    cout<<ans-2<<endl;
    return 0;
}
