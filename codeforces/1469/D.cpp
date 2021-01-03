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
        vector<pii>vec;
        if(n <= 64) {

            
            for(int i = n-1 ; i >= 3 ; i-- ) vec.push_back({i, n});
            int tmp = n;

            while(tmp > 1) {
                vec.push_back({n, 2});
                tmp = (tmp+1)/2;
            }
        }
        else {

            for(int i = n-1 ; i >= 3 ; i--) {
                if(i == 64) continue;
                vec.push_back({i, n});
            }

            int tmp = n;
            while(tmp > 1) {
                vec.push_back({n, 64});
                tmp = (tmp-1)/64 + 1;
            }

            tmp = 64;
            while(tmp > 1) {
                vec.push_back({64, 2});
                tmp/=2;
            }
        }

        assert(vec.size() <= n + 5);

        cout<<vec.size()<<'\n';
        for(auto x : vec) cout<<x.uu<<" "<<x.vv<<'\n';
        continue;

    }
    return 0;

}