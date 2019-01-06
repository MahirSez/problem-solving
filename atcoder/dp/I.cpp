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
int n , vis[4000][4000];
double ara[4000] , dp[4000][4000];

double solve(int id , int heads) {

    if( id == n) {
        if( heads > 0) return 1;
        return 0;
    }

    if( vis[id][heads] ) return dp[id][heads];

    vis[id][heads] = 1;

    double tmp = ara[id] * solve(id+1 , heads + 1) + (1- ara[id]) * solve(id+1 , heads-1);

    return dp[id][heads] = tmp;

}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    double ans = solve(0, 0);
    cout<<setprecision(12)<<fixed<<ans<<endl;
    return 0;
}
