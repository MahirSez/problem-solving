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

vector<int>rec[N];

int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i =1; i <=n ; i++ )rec[i].clear();

        for(int i = 1; i <=n ; i++) {
            int tmp;
            cin>>tmp;
            rec[tmp].push_back(i);
        }

        int ans = INF;
        for(int i =1 ; i <=n ; i++ ) {
            if(rec[i].size() == 0) continue;
            int cnt = 0;

            if(rec[i][0] != 1) cnt++;
            if(rec[i].back() != n) cnt++;

            for(int j = 1 ; j < rec[i].size() ; j++ ) {
                int id1 = rec[i][j-1];
                int id2 = rec[i][j];
                if(id2 - id1 ==1) continue;
                cnt++;
            }
            ans = min(ans, cnt);
        }
        cout<<ans<<'\n';
    }
    return 0;
}