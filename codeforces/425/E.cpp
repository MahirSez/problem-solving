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

const int N = 550;

int dp[N][N];

int main()  {
    fastio;

    int n , k;
    cin>>n>>k;

    vector<ll>pow2(N*N);

    pow2[0] = 1;
    for(int i =1 ; i < N*N ; i++ ) pow2[i] = (pow2[i-1] * 2) %MOD;

    for(int i =1 ; i <= n+1 ; i++) {
        dp[i][0] = 1;
    }

    for(int kk = 1 ; kk <= k ; kk++ ) {

        for(int i = n ; i >= 1 ; i-- ) {

            for(int j = i ; j <= n ; j++ ) {

                ll tmp1 = dp[j+1][kk-1];
                ll tmp2 = pow2[j - i + 1] - 1 + MOD;
                tmp1 = (tmp1 * tmp2) % MOD;

                ll tmp3 = pow2[(n - j) * (j - i + 1)];

                tmp1 = (tmp1 * tmp3) % MOD;

                dp[i][kk] += tmp1;
                dp[i][kk] %= MOD;
            }
            
        }
    }

    cout<<dp[1][k]<<'\n';
    return 0;
}