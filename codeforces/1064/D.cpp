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
int n , m , sx , sy , mxL , mxR;
int dx[] = {1 , -1 , 0, 0 };
int dy[] = {0 ,  0, 1 , -1};
int ara[5000][5000]  ;
int rt[5000][5000] , lt[5000][5000];

void print()
{
    for(int i =0 ; i < n ;i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            cout<<ara[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

}
bool ok3(int x , int y,int px ,int py ) {

    if( x >= 0 && y >=0 && x < n && y < m && ara[x][y]!=-1) {
        return (lt[x][y] > lt[px][py] || rt[x][y] > rt[px][py]);
    }
    return false;
}

bool ok2(int x , int y , int px , int py) {
    if( x >= 0 && y >=0 && x < n && y < m && ara[x][y]!=-1) {
        if(lt[x][y] == lt[px][py] +1)
            return rt[x][y] > rt[px][py];
        return lt[x][y] > (lt[px][py] + 1);
    }
    return false;
}

bool ok1(int x , int y , int px , int py) {
    if( x >= 0 && y >=0 && x < n && y < m &&ara[x][y]!=-1) {
        if(rt[x][y] == rt[px][py] +1)
            return lt[x][y] > lt[px][py];
        return rt[x][y]  > (rt[px][py] + 1);
    }
    return false;
}



void bfs() {

    queue<pii>q;
    ara[sx][sy] = 1 ;


    q.push({sx,sy});
    for(int i =0 ; i < n ; i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            lt[i][j] = rt[i][j] = INF;
        }
    }
    rt[sx][sy] = 0;
    lt[sx][sy] = 0;
//    cout<<mxL<<" "<<mxR<<endl;
//    print();

    while( !q.empty() ) {

        int tx = q.front().uu;
        int ty = q.front().vv;
//        cout<<tx<<" "<<ty<<endl;
        q.pop();

        for(int i =0 ; i < 2 ; i++ ) {
            int x = tx + dx[i];
            int y = ty + dy[i];
            if( ok3(x,y,tx,ty) ) {
                ara[x][y] = 1;
                lt[x][y] = lt[tx][ty];
                rt[x][y] = rt[tx][ty];
                q.push({x,y});
            }
        }
        //rt
        if(  rt[tx][ty]  < mxR ) {
            int x = tx + dx[2];
            int y = ty + dy[2];
            if(ok1(x,y,tx,ty) ) {
                ara[x][y] = 1;
                lt[x][y] = lt[tx][ty];
                rt[x][y] = rt[tx][ty] + 1;
                q.push({x,y});
            }
        }
        //lt
        if(  lt[tx][ty]  < mxL ) {
            int x = tx + dx[3];
            int y = ty + dy[3];
            if( ok2(x,y,tx,ty)) {
                ara[x][y] = 1;
                lt[x][y] = lt[tx][ty] + 1;
                rt[x][y] = rt[tx][ty];
                q.push({x,y});
            }
        }

    }
}



int main()
{
    fastRead;
    cin>>n>>m;
    cin>>sx>>sy;
    cin>>mxL>>mxR;
    sx--;
    sy--;
    for(int i =0 ; i < n ; i++ ) {
        string str;
        cin>>str;
        for(int j = 0; j < m ; j++ ) {
            if( str[j] == '*') ara[i][j] = -1;
        }
    }

//    print();
    bfs();
    int cnt = 0;
    for(int i =0 ; i < n ;i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            if( ara[i][j] == 1) cnt++;
        }
    }
//    print();
    cout<<cnt<<endl;
    return 0;
}
/*
3 7
3 4
2 2
.......
*.***.*
.......
*/
