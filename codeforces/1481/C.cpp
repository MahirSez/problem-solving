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
vector<int>pos[N];


int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {

        int n, m;
        cin>>n>>m;
        vector<int>v1(n), v2(n), ans(m ,-1);

        for(int i =0; i <n ; i++) cin>>v1[i];
        for(int i =0; i <n ; i++) cin>>v2[i];

        for(int i =0 ; i <= n ; i++ ) pos[i].clear();

        for(int i = 0 ; i < m ; i++) {
            int col;
            cin>>col;
            pos[col].push_back(i);
        }
        int ok = 1;
        int last = -1;

        for(int i = n-1; i >=0 ; i-- ) {
            if(v1[i] == v2[i]) continue;

            if(pos[v2[i]].size() == 0) {
                ok = 0;
                break;
            }

            int id = pos[v2[i]].back();
            pos[v2[i]].pop_back();
            ans[id] = i+1;
            last = max(last , id);
        }
        if(!ok) {
            cout<<"NO\n";
            continue;
        }
        for(int  i = n-1 ;i >=0 ; i-- ) {
            while(pos[v2[i]].size() > 0) {
                int id = pos[v2[i]].back();
                pos[v2[i]].pop_back();
                ans[id] = i+1;
                last = max(last , id);
            }
        }

        for(int i = 0 ; i < m ; i++ ) {
            if(ans[i] != -1) continue;
            if(i <= last) ans[i] = ans[last];
            else ok = 0;
        }
        // cout<<"--"<<last<<'\n';
        // for(auto x : ans) cout<<x<<" ";
        // cout<<'\n';

        if(!ok) cout<<"NO\n";
        else {
            cout<<"YES\n";
            for(auto x : ans) cout<<x<<" ";
            cout<<'\n';
        }
        
    }
    return 0;
}