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
int ara[200][200];
int mark[200][200];

int main()  {
    fastio;

    
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        memset(ara , 0, sizeof ara);
        memset(mark , 0, sizeof mark);

        for(int i =1 ; i <=n ; i++ ) {
            for(int j =1 ; j <=m ; j++ ) {
                cin>>ara[i][j];
            }
        }
        ll ans = 0;

        for(int i =1 ; i <=n ; i++ ) {
            for(int j = 1 ; j <=m ; j++ ) {
                if(mark[i][j]) continue;

                set<pii>s;
                s.insert({i,j});
                s.insert({i, m- j + 1});
                s.insert({n - i + 1, j});
                s.insert({n - i + 1, m - j + 1});

                mark[i][j] = 1;
                mark[i][m - j + 1] = 1;
                mark[n - i + 1][j] = 1;
                mark[n - i + 1][m - j + 1] = 1;

                vector<int>vec;
                for(auto x : s) vec.push_back(ara[x.uu][x.vv]);
                sort(vec.begin() , vec.end());


                if(vec.size() == 1) continue;
                else if(vec.size() == 2 ) ans += vec[1] - vec[0];
                else if(vec.size() == 3) ans += vec[2] - vec[0];
                else if(vec.size() == 4) ans += vec[3] - vec[0] + vec[2] - vec[1];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}