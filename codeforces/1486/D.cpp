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

    int n, k;
    cin>>n>>k;
    vector<int>vec(n+1);
    for(int i =1; i<= n; i++) cin>>vec[i];

    int lo = 1, hi = n, ans = -1;
    while(lo<= hi) {
        int mid = (lo+hi)/2;
        vector<ll>sum(n+1), mnpref(n+1);
        int ok = 0;
        for(int i = 1; i <=n ; i++ ) {
            sum[i] = sum[i-1] + (vec[i] >= mid ? 1 : -1);
            mnpref[i] = min(mnpref[i-1], sum[i]);    

            // cout<<sum[i]<<" ";        
        }
        // cout<<'\n';
        for(int i = k ; i <= n ; i++ ) {
            if(sum[i] - mnpref[i-k] > 0) ok = 1;

            // cout<<i<<" "<<i-k<<" -- "<<sum[i]<<" "<<mnpref[i-k]<<'\n';
        }
        // cout<<mid<<" "<<ok<<'\n';
        
        if(ok) {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;

        // cout<<lo<<" "<<hi<<'\n';
    }
    int ret = 0;
    // cout<<ans<<'\n';

    for(int i =1 ; i <=n ; i++ ) {
        if(vec[i] <= ans) ret = max(ret, vec[i]);
    }
    cout<<ret<<'\n';
    return 0;

}