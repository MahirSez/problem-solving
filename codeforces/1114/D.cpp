#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
vector<int>v;
int dp[5001][5001];

int solve(int l , int r) {
    if( l >=r) return 0;
    int &ret = dp[l][r];
    if( ret != -1) return ret;
    ret = INF;
    if( v[l] == v[r]) ret = min(ret , 1 + solve(l+1 , r-1));
    ret = min( ret , 1 + solve(l+1 , r));
    ret = min(ret , 1 + solve(l , r-1));
    return ret;
}


int main()
{
    fastRead;
    cin>>n;
    int last = 0 , now;
    for(int i =0 ; i < n ; i++ ) {
        cin>>now;
        if( last != now) v.push_back(now);
        last = now;
    }
    memset(dp , -1 , sizeof dp);
    cout<<solve(0 , v.size() - 1)<<endl;
    return 0;

}