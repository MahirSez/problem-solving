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
        vector<ll>vec(n), cnt(n);
        for(int i =0 ; i< n ; i++ ) cin>>vec[i];
        ll ans = 0;
        for(int i = 0 ; i < n ; i++ ) {
            ans += max(0LL, vec[i] - cnt[i] - 1);
            int frm = i+2, to = min(1LL*(n-1), i + vec[i]);
            for(int j = frm ; j <= to ; j++) cnt[j]++;
            if(cnt[i] < vec[i]) continue;
            if(i < n-1) cnt[i+1] += cnt[i] - vec[i] + 1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}