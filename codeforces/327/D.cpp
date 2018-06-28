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
int n , m ,ara[600][600];
int dx[] = {0 , 0 , -1 , 1};
int dy[] = {1 , -1 , 0 , 0};
string str;
vector<pair<char ,pii> >v;

void dfs(int x , int y ) {
    ara[x][y] = 1;
    v.push_back(make_pair('B' , make_pair(x,y) ) );

    for(int i = 0 ; i < 4; i++ ) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if( tx >=1 && tx <=n && ty >=1 && ty<= m && ara[tx][ty] ==0 ) {
            dfs(tx,ty);
        }
    }
    for(int i =0 ;i < 4 ;i++ ) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if( tx >=1 && tx <=n && ty >=1 && ty <= m && ara[tx][ty] == 1){
            ara[x][y] = 2;
            v.push_back(make_pair('D' , make_pair(x,y) ));
            v.push_back(make_pair('R' , make_pair(x,y) ));
            break;
        }
    }
}


int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =1 ; i <= n ; i++ ) {
        cin>>str;
        str = "*" + str;
        for(int j =1 ; j <= m ; j++ ) {
            if( str[j] == '#') ara[i][j] = -1;
            else ara[i][j] = 0;
        }
    }
    for(int i =1 ; i<= n ; i++ ) {
        for(int  j=1 ; j<= m ; j++ ) {
            if( ara[i][j] == 0) {
                dfs(i,j);
            }
        }
    }
    printf("%d\n",v.size());
    for(int i = 0 ;i < v.size() ; i++ ) {
        printf("%c %d %d\n",v[i].uu , v[i].vv.uu,  v[i].vv.vv);
    }
    return 0;
}
