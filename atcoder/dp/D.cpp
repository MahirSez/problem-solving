#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , W , wt[200] ;
ll val[200] , dp[200][100005];


ll solve(int id ,int taken) {

     if( id == n ) return 0;
     ll &ret = dp[id][taken];
     if( ret != -1 )return ret;

     ret = solve(id+1 , taken);

     if( taken + wt[id] <= W)
        ret= max(ret , val[id] + solve(id+1 , taken+wt[id]));
     return ret;
}

int main(){
    fastRead;
    cin>>n>>W;
    for(int i =0 ; i < n ; i++ ) {
        cin>>wt[i]>>val[i];
    }
    memset(dp , -1 , sizeof dp);
    cout<<solve(0 , 0 )<<endl;
    return 0;
}
