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

        vector<int>ans;
        int now = n*4;
        while(now >= 1 and ans.size() < n) {

            if(ans.size() == 0 ) {
                ans.push_back(now);
                now--;
                continue;
            }
            int ok = 1;
            for(auto x : ans ){
                int xx = __gcd(x , now);
                if(xx == x || xx == now || xx == 1) ok = 0;
            }
            if(ok)ans.push_back(now);
            now--;
        }
        assert(ans.size() == n);

        for(auto x : ans) cout<<x<<" ";
        cout<<'\n';

    }
    return 0;
}