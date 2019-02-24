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
int n , ara[100][100];
int dx[] = {0 , 0 ,-1 , 1};
int dy[] = {1 , -1, 0 , 0};
int frmX , frmY , toX , toY;
vector<pii>frm , to;


bool inside(int x , int y) {

    return (x>=0 && y>=0 && x < n && y < n && ara[x][y] !=-1);
}

void dfs(int x , int y , int col) {

    ara[x][y] = col;
    if( col ==1 ) frm.push_back({x,y});
    if( col ==2 ) to.push_back({x,y});
    for(int i =0 ; i < 4; i++ ) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(inside(xx , yy) && ara[xx][yy] != col  ) {
            dfs(xx ,yy ,col);
        }
    }
}
int cost(pii p1 , pii p2) {

    return ( (p1.uu - p2.uu)*(p1.uu - p2.uu) + (p1.vv - p2.vv)*(p1.vv - p2.vv) ); 
}


int main()
{
    fastRead;
    cin>>n;
    cin>>frmX>>frmY>>toX>>toY;
    frmX--;
    frmY--;
    toX--;
    toY--;
    for(int i =0 ; i < n ; i++ ) {
        string str;
        cin>>str;
        for(int j =0 ; j < n ; j++ ) {

            if( str[j] =='1') ara[i][j] = -1;
        }
    }

    dfs(frmX , frmY , 1);
    
    dfs(toX , toY , 2);

    int ans = INF;
    for(int i =0 ; i < frm.size() ; i++ ) {
        for(int j =0 ; j < to.size() ; j++  ) {
            ans = min(ans , cost(frm[i] , to[j] ));
        }
    }
    cout<<ans<<endl;
    // for(int i =0 ; i < frm.size() ; i++ ) {
    //     cout<<frm[i].uu<<" "<<frm[i].vv<<endl;
    // }


    // for(int i =0 ; i < n ; i++) {
    //     for(int j =0 ; j < n ; j++ ) {
    //         cout<<ara[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}