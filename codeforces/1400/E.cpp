#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 5e3 + 6;

int  dp[N][N] , ara[N];
int n;
int solve(int id , int last) {

    if(id == n +1) return 0;

    int &ret = dp[id][last];
    if( ret != -1 ) return ret;

    ret = INF;

    if(ara[id] >= ara[last] ) {
        ret = min(ret , 1 + solve(id+1 , last) );
        ret = min(ret , ara[id] - ara[last] + solve(id+1 , id ));
    }
    else ret = min(ret , solve(id+1 , id));
    return ret;
}

int main() {
    fastio;
    cin>>n;
    for(int i =1 ; i <= n ; i++ ) cin>>ara[i];
    memset(dp , -1 , sizeof dp);
    cout<<solve(1, 0)<<'\n';
    return 0;
}