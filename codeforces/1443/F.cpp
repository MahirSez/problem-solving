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
const ll MOD = 998244353 ;

const int N = 1e6 + 6;

int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int>vec(n+1) , pos(n+1)  , b(n+1), mark(n+1);
        for(int i =1 ; i <=n ; i++ ) {
            cin>>vec[i];
            pos[vec[i]] = i;
        }

        for(int i =1 ; i <=k ; i++ ) cin>>b[i], mark[b[i]] = 1;

        ll ans = 1;

        for(int i = 1; i <= k ; i++) {
            int cnt = 0;
            int p = pos[b[i]];

            if(p > 1 && mark[vec[p-1]] == 0) cnt++;
            if(p < n && mark[vec[p+1]] == 0) cnt++;
            ans = (ans * cnt)%MOD;
            mark[vec[p]] = 0;

        }

        cout<<ans<<'\n';

    }
    return 0;
}