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

int dp[505][505][505], ara[505];
int n, x;

int solve(int id, int haate, int prev) {

    // cout<<id<<'\n';
    if(id == n) return 0;

    int &ret = dp[id][haate][prev];
    if( ret != -1) return ret;

    ret = INF;

    if(prev > ara[id]) {
        if( ara[id] <= haate) return INF;
        if( haate < prev) return INF;
        ret = 1 + solve(id+1, ara[id], haate);
    }
    else {
        ret = solve(id+1, haate, ara[id]);
        if(ara[id] > haate && haate >= prev) ret = min(ret , 1 + solve(id+1, ara[id], haate) );
    }

    // cout<<id<<" "<<haate<<" "<<prev<<" "<<ret<<'\n';
    return ret;


}

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        
        cin>>n>>x;
        for(int i = 0 ; i <=n ; i++ ) {
            for(int j =0 ; j <=500; j++ ) {
                for(int k = 0 ;k <=500; k++ ) {
                    dp[i][j][k] = -1;
                }
            }
        }
        for(int i =0 ; i < n ; i++ ) cin>>ara[i];
        int ans = solve(0, x, 0);
        if(ans == INF) ans = -1;

        cout<<ans<<'\n';
    }
    return 0;
}