#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;
    int n ,k;
    cin>>n>>k;
    vector<ll>p(n+1) , c(n+1);

    for(int i =1 ; i <=n ; i ++ ) cin>>p[i];
    for(int i =1 ; i <=n ; i ++ ) cin>>c[i];

    ll ans = -INF;

    for(int i =1 ; i <=n ; i++ ) {

        vector<ll>rec;

        int now = i;
        
        while(1) {
            now = p[now];
            rec.push_back(c[now]);
            if(now == i) break;
        }
        ll sum = 0;

        int nn = rec.size();
        for(int i =0 ; i < min(k , nn) ; i++ ) {
            sum += rec[i];
            ans = max(ans , sum);
        }


        ll x = k / nn;
        ll y = k % nn;

        if(x == 0 ) continue;

        x--;
        for(int i =0 ; i < y ; i++ ) rec.push_back(rec[i]);

        sum *= x;
        if(x) ans = max(ans , sum);

        for(auto x : rec) {
            sum += x;
            ans = max(ans , sum);
        }

    }
    cout<<ans<<'\n';
    return 0;
}