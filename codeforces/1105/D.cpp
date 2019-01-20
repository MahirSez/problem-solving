#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define ppp         pair<pii ,pii>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
int ara[2000][2000];
int spd[20];
int ans[20];
int n , m , p;
void print()
{
    for(int i =0 ; i < n ; i++ ) {
        for(int j = 0 ; j < m ; j++ ) {
            cout<<ara[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void bfs() {

    queue<ppp>q[20];
    int baki = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j =0 ; j < m ; j++ ) {
            if(ara[i][j]==0) baki++;

            if( ara[i][j] <=0 ) continue;
            else q[ara[i][j]].push({{i,j } , {0,0} });


        }
    }

    for(int now = 0 ;  ; now++) {

        bool done= true;

        for(int i =1 ; i<= p ; i++ ) {
            if(!q[i].empty()) done= false;
        }

        if( done ) break;
//        print();

        for(int i =1 ; i<= p ; i++ ) {
            int id = i;
            int limit = spd[i];

            while(!q[id].empty()) {

                int x = q[id].front().uu.uu;
                int y = q[id].front().uu.vv;
                int lvl = q[id].front().vv.uu;
                int tmp = q[id].front().vv.vv;
//                if( id == 1&& x == 1 && y == 0 ){
//                    cout<<"wtf"<<tmp<<" "<<now<<endl;
//                }

                if( tmp != now ) break;
                q[id].pop();

                for(int k =0 ; k < 4; k++ ) {

                    int xx = x + dx[k];
                    int yy = y + dy[k];
//                    cout<<id<<" --- "<<x<<" "<<y<<" to "<<xx<<" "<<yy<<" -> "<<( xx >=0 && xx < n && yy>=0 && yy < m && ara[xx][yy] == 0)<<endl;


                    if( xx >=0 && xx < n && yy>=0 && yy < m && ara[xx][yy] == 0) {

                        ara[xx][yy] = id;
//                        print();
                        if( lvl+1 == limit) q[id].push({ {xx , yy} , {0,now+1} } );
                        else q[id].push({ {xx , yy} , {lvl+1,now} });
                    }
//                    print();
                }
            }
        }
    }

}


int main()
{
    fastRead;
    cin>>n>>m>>p;
    for(int i =1 ; i<= p ; i++ ) cin>>spd[i];
    for(int i =0 ; i < n ; i++ ) {
        string str;
        cin>>str;
        for(int j =0 ; j < m ; j++ ) {
            if( str[j] == '#') ara[i][j] = -1;
            else if(str[j] == '.') continue;
            else ara[i][j] = (str[j] - '0');
        }
    }

    bfs();
    for( int i = 0; i < n ; i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            if( ara[i][j] == -1) continue;
            else ans[ara[i][j]]++;
        }
    }
    for(int i =1 ; i<= p ; i++ ) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
