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
int ara[250][250];

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        memset(ara , 0 , sizeof ara);
        for(int i = 1; i <=n ; i++ ) {
            string s;
            cin>>s;
            for(int j =1 ; j <=n ; j++ ) {
                if(s[j-1] =='1') ara[i][j] = 1;
            }
        }

        vector<pii>ans1 , ans2;
        if(ara[1][2] == 1) ans1.push_back({1,2});
        if(ara[2][1] == 1) ans1.push_back({2,1});
        if(ara[n][n-1] == 0) ans1.push_back({n,n-1});
        if(ara[n-1][n] == 0) ans1.push_back({n-1,n});

        if(ara[1][2] == 0) ans2.push_back({1,2});
        if(ara[2][1] == 0) ans2.push_back({2,1});
        if(ara[n][n-1] == 1) ans2.push_back({n,n-1});
        if(ara[n-1][n] == 1) ans2.push_back({n-1,n});

        if(ans1.size() > ans2.size() ) ans1 = ans2;
        assert(ans1.size() <=2 );
        cout<<ans1.size()<<'\n';
        for(auto x : ans1) cout<<x.uu<<" "<<x.vv<<'\n';
    }
    return 0;
    
}