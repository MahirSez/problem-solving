#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int n , nxt[MAX];
ll ara[MAX] ;
bool taken[MAX] , shuru[MAX];

bool exists( ll item) {

    for(int i =0 ; i < n ;i++ ) {

        if( ara[i] == item && taken[i] == false)
            return true;
    }
    return false;
}

int fnd(ll item) {
    for(int i =0 ; i < n ;i++ ) {
        if( ara[i] == item && taken[i] == false)
            return i;
    }
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n; i++ ) cin>>ara[i];
    memset( nxt , -1 , sizeof nxt);
    for(int i =0 ; i < n ;i++) {

        ll tmp = ara[i];
        if( tmp %3 == 0 && exists(tmp/3)) {

            int id = fnd(tmp/3);
            taken[id] = true;
            nxt[i] = id;
            shuru[id] = true;
        }
        else if( exists(tmp*2) ) {

            int id = fnd(tmp*2);
            taken[id] = true;
            nxt[i] = id;
            shuru[id] = true;
        }
        else {
            nxt[i] = i;
        }

    }
    int strt = -1;
    for(int i =0 ; i < n ; i++ ) {
        if( shuru[i]  == false ) {

            strt = i;
        }
    }

    while( nxt[strt] != strt) {
        cout<<ara[strt]<<" ";
        strt = nxt[strt];
    }
    cout<<ara[strt]<<endl;
    return 0;
}
