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

int dp[300][500], ara[300];
int n;

int solve(int id, int _tim) {
    if(id == n) return 0;
    if(_tim == 2*n) return INF;

    int &ret = dp[id][_tim];
    if(ret != -1) return ret;

    ret = min(solve(id+1, _tim+1) + abs(ara[id]- _tim) , solve(id, _tim+1));
    return ret;

}

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        memset(dp, -1,  sizeof dp);

        for(int i = 0; i <n ; i++ ) cin>>ara[i];
        sort(ara, ara + n);
        cout<<solve(0,1)<<'\n';

    }
    return 0;
    
    
}