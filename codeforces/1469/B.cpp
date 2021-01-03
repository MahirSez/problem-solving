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

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>sum1(n+1);
        for(int i =1 ; i <=n ; i++ ) {
            cin>>sum1[i];
            sum1[i] += sum1[i-1];
        }
        int m;
        cin>>m;
        vector<int>sum2(m+1);
        for(int i =1 ; i <=m ; i++ ) {
            cin>>sum2[i];
            sum2[i] += sum2[i-1];
        }

        int ans = 0;
        for(int i =0 ; i <= n ; i++ ) {
            for(int j =0 ; j <= m ; j++ ) {
                ans = max(ans , sum1[i] + sum2[j]);
            }
        }

        cout<<ans<<'\n';

    }
    return 0;
}