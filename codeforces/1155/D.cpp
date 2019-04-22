#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pip 		pair<int,pii>
#define INF     	1e18
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
ll x , ara[MAX] , dp[MAX][7], vis[MAX][7];

ll solve(int id , int state) {

    if( id == n ||state == 4) return 0;


    ll &ret = dp[id][state];

    if( vis[id][state] ) return ret;


    vis[id][state] = 1;


    ret = -INF;

    if( state == 0) {
        ret = max(ret , solve(id+1 , 0)) ;
        ret = max(ret , ara[id] + solve(id+1 , 1) ) ;
        ret = max(ret , ara[id] * x + solve(id+1 , 2)) ;
    }

    else if( state == 1) {

        ret = max(ret , ara[id] + solve(id+1 , 1));


        ret = max(ret , ara[id] *x + solve(id+1 , 2));
        ret = max(ret ,  solve(id+1 , 4));
    }
    else if( state == 2) {
        ret = max(ret , ara[id] *x + solve(id+1 , 2));
        ret = max(ret , ara[id]  + solve(id+1 , 3));
        ret = max(ret , solve(id+1 , 4));
    }
    else if( state == 3) {
        ret = max(ret , ara[id]  + solve(id+1 , 3));
        ret = max(ret , solve(id+1 , 4));
    }
    return ret;
}


int main()
{
    fastRead;
    cin>>n>>x;
    for(int i =0 ; i < n ; i++) cin>>ara[i];
    cout<<solve(0, 0)<<endl;
    return 0;
}
