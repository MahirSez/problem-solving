#include <bits/stdc++.h>
#define ll          long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e12
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
struct point {
    ll x , y;
} p1;
int n;
point ara[MAX];
int used[MAX];


bool sameLine(point p1 , point p2 , point p3) {

    return (p1.y - p2.y)*(p1.x - p3.x)==(p1.y - p3.y)*(p1.x - p2.x);
}

bool solve(point p1 ,point p2) {

    memset( used , 0 , sizeof used );

    for(int i = 0 ; i < n ;i++ ) {

        if( sameLine(p1 , p2 , ara[i]) )
            used[i] = 1 ;
    }
    point tmp1 , tmp2;
    tmp1.x = INF , tmp1.y =INF , tmp2.x = INF , tmp2.y = INF;

    for(int i =0 ; i < n ; i++ ) {
        if(used[i] ==0 ) {

            if( tmp1.x == INF) tmp1 = ara[i] ;
            else if( tmp2.x == INF) tmp2 = ara[i] ;
        }
    }

    if( tmp2.x == INF) return true;
    for(int  i =0 ; i < n ; i++ ) {

        if( used[i] ==0 && !sameLine(tmp1 , tmp2 , ara[i]) )
            return false;
    }
    return true;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ;i++ ) {
        cin>>ara[i].x>>ara[i].y;
    }

    if( n <=3 ) {
        cout<<"YES"<<endl;
        return 0;
    }

    point p1  = ara[0];
    point p2  = ara[1];
    point p3  = ara[2];

    bool ok = false;
    for(int i =0 ; i < 3 ; i++ )
        for(int j = i+1 ; j < 3 ; j++ ) {
            ok |= solve(ara[i] , ara[j]);
//            cout<<i<<" "<<j<<" "<<ok<<endl;
        }

    if( ok ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
