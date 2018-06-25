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
int n , k, ara[5][51] , cnt;
vector<pair<int,pii> > v;

void print() {
    cout<<endl;
    for(int i =1 ; i <= 4 ; i++ ) {
        for(int j =1 ; j <= n ;j++ ) {
            cout<<ara[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool ok() {

    for(int i = 2 ; i<= 3; i++ ) {
        for(int j =1 ; j<= n ;j++ ) {
            if( ara[i][j]) return false;
        }
    }
    return true;
}
void check() {
    for(int i = 1 ; i <= n ; i++ ) {
        if( ara[1][i]  && ara[1][i] == ara[2][i] ) {
            cnt++;
            ara[2][i] = 0;
            v.push_back(make_pair(ara[1][i] , make_pair(1 , i)) );
        }
        if( ara[4][i] && ara[3][i] == ara[4][i] ) {
            cnt++;
            ara[3][i] = 0;
            v.push_back(make_pair(ara[4][i] , make_pair(4 , i)) );
        }
    }
}
int main()
{
    fastRead;
    cin>>n>>k;
    for(int i =1 ; i <= 4 ; i++ ) {
        for(int j = 1 ; j <= n ; j++ ) {
            cin>>ara[i][j];
        }
    }
    check();
    if( cnt== 0  && k == 2*n){
        cout<<-1<<endl;
        return 0;
    }

    while( 1 ) {

        if( ok() ) {
            cout<<cnt<<endl;
            for(int i =0 ; i < cnt; i++ ) {
                cout<<v[i].uu<<" "<<v[i].vv.uu<<" "<<v[i].vv.vv<<endl;
            }
            return 0;
        }

        for(int x = 2 ; x <= 3 ; x++ ) {
            for(int y = 1; y <= n; y++ ) {

                if( ara[x][y] ) continue;

                if( x ==2 ) {
                    if( y > 1 ) {
                        if( ara[x][y-1] == 0) continue;
                        ara[x][y] = ara[x][y-1];
                        ara[x][y-1] = 0;
                        cnt++;
                        v.push_back(make_pair(ara[x][y] , make_pair(x,y)));
                        check();
                    }
                    else {
                        if( ara[x+1][y] == 0) continue;
                        cnt++;
                        ara[x][y] = ara[x+1][y];
                        ara[x+1][y] = 0;
                        v.push_back(make_pair(ara[x][y] , make_pair(x,y)));
                        check();
                    }
                }
                else {
                    if( y < n) {
                        if( ara[x][y+1] == 0) continue;
                        ara[x][y] = ara[x][y+1];
                        ara[x][y+1] = 0;
                        cnt++;
                        v.push_back(make_pair(ara[x][y] , make_pair(x,y)));
                        check();
                    }
                    else {
                        if( ara[x-1][y] == 0) continue;
                        cnt++;
                        ara[x][y] = ara[x-1][y];
                        ara[x-1][y] = 0;
                        v.push_back(make_pair(ara[x][y] , make_pair(x,y)));
                        check();
                    }
                }
            }
        }
    }
    return 0;
}
