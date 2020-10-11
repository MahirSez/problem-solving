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

int wtsum[N], mxlen[N];

int main() {
    fastio;

    int n , m;
    cin>>n>>m;

    vector<int>wt(n), perm(n);

    int mxwt = 0;

    for(int i =0 ; i < n ; i++ ) cin>>wt[i] , mxwt = max(mxwt , wt[i]) , perm[i] = i;

    for(int mask =0 ; mask < (1<<n) ; mask++ ) {

        for(int i =0 ; i < n ; i++ ) {
            if(mask & (1<<i)) wtsum[mask] += wt[i];
        }
    }

    while(m--) {
        int l , v;
        cin>>l>>v;

        if(mxwt > v) {
            cout<<-1<<'\n';
            return 0;
        }

        for(int mask = 0 ; mask < (1<<n) ; mask++) {

            if(wtsum[mask] <= v) continue;

            mxlen[mask] = max(mxlen[mask] , l); 
        }
    }
    int ans = INF;

    do {
        int mx = 0;
        vector<int>dp(n+1);
        for(int i = 1 ; i <= n ; i++ ) {
            int mask = 0;
            for(int j = i ; j >= 1 ; j--) {
                mask |= (1<<perm[j-1]);
                dp[i] = max(dp[i] , dp[j] + mxlen[mask]);
            }
        }
        ans = min(ans , dp[n]);
    } while(next_permutation(perm.begin() , perm.end()));

    cout<<ans<<'\n';
    return 0;
}