#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS		1e-8
#define MAX		1000006
using namespace std;
int ara[100][100];
int  ro , col ;
string str;
int cnt;

bool valid(int x, int y) {


    if( x < ro && x>=0 && y < col && y>=0 && ara[x][y] != -1 )
        return true;
    return false;
}

bool ok( int up, int dwn , int lft , int rt) {

//    cout<<up<<dwn<<lft<<rt<<endl;

    pii s , e;

    for( int  i = 0 ; i < ro ; i++) {

        for( int j = 0; j < col ; j++) {

            if( ara[i][j]==2) s = {i,j};
            if (ara[i][j] == 3) e = {i,j};
        }
    }


    for( int  i = 0 ; i < str.size(); i++ ) {

        int tmp = str[i] - '0';

        pii nw;

        if( tmp == up ) {

            nw = {s.uu -1, s.vv};

        }

        else if( tmp == dwn) {

             nw = {s.uu +1, s.vv};

        }

        else if( tmp == lft) {

            nw = {s.uu, s.vv-1};
        }
        else  {
            nw = {s.uu, s.vv+1};
        }

        if( valid(nw.uu, nw.vv) ==false ) return false;

        if( nw.uu == e.uu && nw.vv == e.vv) return true;

        s = {nw.uu , nw.vv};

    }
    return false;

}

int main()
{
    cin>>ro>>col;
    for(int i =0 ; i < ro; i++) {

        cin>>str;
        for( int  j = 0 ; j < str.size() ; j++)  {

            if( str[j] == '#' ) ara[i][j] = -1;
            else if( str[j] == 'S' ) ara[i][j] = 2;
            else if( str[j] == 'E' ) ara[i][j] = 3;
        }
    }


    cin>>str;
    int a=0;
    for( int  i =0 ; i <4; i ++) {

        for( int  j = 0; j < 4; j ++) {

            for( int  k =0 ; k < 4; k++) {

                for( int  l =0 ; l < 4; l++ ){

                    if( i==j || i== k || i==l || j==k || j==l ||k ==l)
                        continue;

                    if( ok(i,j,k,l) ) cnt++;

                    a++;
                }
            }
        }
    }


    cout<<cnt<<endl;
    return 0;
}
