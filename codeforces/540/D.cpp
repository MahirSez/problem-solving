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
int rck , pap , sci, vis[101][101][101] ;
double dp[101][101][101];

double solve(int r , int s , int p) {
    if( r == 0 ) return 0;
    if( p == 0 ) return 1;
    if( p == 0 && s == 0 ) return 1;
    if( s == 0 ) return 0;
    int &ret = vis[r][s][p];
    if( ret ) return dp[r][s][p];
    ret = 1;
    double hor = (r*s + s*p + r*p)*1.00;
    double rs = (r*s*1.00);
    double rp = (r*p*1.00);
    double sp = (p*s*1.00);
    double ans = 0;
    ans += (rs/hor)* solve(r , s-1 , p);
    ans += (sp/hor)* solve(r , s , p-1);
    ans += (rp/hor)* solve(r-1 ,s , p);
    return dp[r][s][p] = ans;
}


int main()
{
    cin>>rck>>sci>>pap;
    double d1 = solve(rck, sci , pap);
    double d2 = solve(sci ,pap , rck);
    double d3 = solve(pap , rck , sci);
    cout<<setprecision(15)<<fixed<<d1<<" "<<d2<<" "<<d3<<"\n";
    return 0;
}
