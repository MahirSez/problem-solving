#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         100005
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll dp[MAX][3] , a[MAX] , b[MAX];
int n;

ll solve(int id, int last) {
    
    if( id == n ) return 0;
    
    
    ll &ret = dp[id][last];
    if( ret != -1 ) return ret;
    
    ret = 0;
    ret = max(ret , solve(id+1 , 0));
    if( last != 1) ret = max(ret , a[id] + solve(id+1 , 1) );
    if( last != 2) ret = max(ret , b[id] + solve(id+1 , 2) );
    return ret;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>a[i];
    for(int i =0 ; i < n ; i++ ) cin>>b[i];
    
    memset(dp , -1 , sizeof dp);
    cout<<solve(0 , 0 )<<'\n';
    return 0;
}