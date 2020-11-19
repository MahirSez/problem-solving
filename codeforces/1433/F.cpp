#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;
int dp[70][70][35][70], ara[100][100];
int n , m , k;

int solve(int ro, int col , int taken, int modVal) {
    if(ro == n) return (modVal == 0)? 0 : -INF;
    if(col == m || taken == m/2) return solve(ro+1, 0, 0, modVal);
    int &ret = dp[ro][col][taken][modVal];
    if(ret != -1) return ret;

    int ret1 = solve(ro, col+1, taken, modVal);
    int ret2 = solve(ro, col+1, taken+1, (modVal + ara[ro][col])%k ) + ara[ro][col];
    return ret = max(ret1, ret2);
}

int main()  {
    fastio;
    
    cin>>n>>m>>k;

    memset(dp, -1, sizeof dp);
    for(int i =0 ; i < n ; i++ ) {
        for(int j = 0 ; j < m ; j++ ) cin>>ara[i][j];
    }

    cout<<solve(0, 0, 0, 0)<<'\n';
    return 0;
}