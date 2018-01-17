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
#define MOD		1000000007
using namespace std;
int n , t;
double p, sum , dp[5000][5000];
bool vis[5000][5000];

double solve(int id, int time) {

    if( id == n || time == t) return 0;

    if( vis[id][time] == true) return dp[id][time];

    vis[id][time] = true;

    double sum = p * (1 + solve( id+1 , time +1) )+ (1-p) * solve(id , time + 1) ;

    return dp[id][time] = sum;
}
int main()
{
    cin>>n>>p>>t;
    cout<<setprecision(10)<<fixed<<solve(0,0)<<endl;
    return 0;
}
