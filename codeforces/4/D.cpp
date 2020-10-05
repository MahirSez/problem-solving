#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define ppi         pair<pii,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main() {
    int n , w , h;
    cin>>n>>w>>h;

    vector<ppi>rec, ids;
    for(int i =1 ; i <=n ; i++ ) {
        int x , y , id;
        cin>>x>>y;
        if(x <=w || y <= h) continue;
        rec.push_back({ {x,y}, i});
    }
    int nn = rec.size();
    
    if(rec.size() == 0) {
        cout<<0<<'\n';
        return 0;
    }

    sort(rec.begin() , rec.end());

    vector<int>dp(nn);

    dp[0] = 1;
    int ans= 1;

    for(int i = 1 ;i < nn ; i++ ) {
        dp[i] = 1;

        for(int j =0 ; j < i ; j++ ) {
            if(rec[j].uu.uu < rec[i].uu.uu && rec[j].uu.vv < rec[i].uu.vv) {
                dp[i] = max(dp[i] , dp[j] + 1);
            }
        }
        ans = max(ans , dp[i]);
    }

    int id = -1;
    for(int i =0 ; i < nn ; i++ ) {
        if(dp[i] == ans) id = i;
    }
    cout<<ans<<'\n';
    vector<int>tmp;

    while(1) {
        tmp.push_back(rec[id].vv);
        ans--;
        if(ans ==0) break;
        
        for(int i =0 ; i < id ; i++) {
            if(dp[i] == ans && rec[i].uu.uu < rec[id].uu.uu && rec[i].uu.vv < rec[id].uu.vv ) {
                id = i;
            }
        }
    }
    reverse(tmp.begin() , tmp.end());
    for(auto x : tmp) cout<<x<<" ";
    cout<<'\n';

    
    return 0;

    



}