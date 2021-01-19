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
        n+=n;
        vector<int>vec(n);
        for(int i =0; i <n ; i++ ) cin>>vec[i];
        sort(vec.rbegin() , vec.rend());

        map<int,int>mp;
        for(auto x : vec) mp[x]++;


        vector<pii>ans;
        int okk = 0;


        for(int i =1; i <n ; i++ ) {
            ans.clear();

            

            map<int,int>mp1 = mp;

            mp1[vec[i]]--;
            mp1[vec[0]]--;
            ans.push_back({vec[0], vec[i]});

            int mx = vec[0];

            int ok = 1;


            for(auto x : vec) {

                if(mp1[x] == 0) continue;
                mp1[x]--;

                if(mp1[mx-x] ==0) {
                    ok = 0;
                    break;
                }
                else {
                    mp1[mx-x]--;
                    ans.push_back({x, mx-x});
                    mx = x;
                }
            }
            if(ok) {
                okk = 1;
                break;
            }
        }

        if(okk) {
            cout<<"YES\n";
            assert(ans.size() == n/2);
            cout<<ans[0].uu + ans[0].vv<<'\n';
            for(auto x : ans) cout<<x.uu<<" "<<x.vv<<'\n';
        }
        else cout<<"NO\n";

    }
    return 0;
}