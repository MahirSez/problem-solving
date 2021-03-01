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
        int n , u , v;
        cin>>n>>u>>v;
        set<int>st;
        
        int last = -5;
        int ok = 0;
        for(int i =0; i <n ; i++ ) {
            int tmp;
            cin>>tmp;
            st.insert(tmp);
            if(last != -5 and abs(last - tmp) > 1) ok = 1;
            last = tmp;
        }
        if(ok) {
            cout<<0<<'\n';
            continue;
        }

        if(st.size() == 1) {
            int ans = min(u+v, 2*v);
            cout<<ans<<'\n';
        }
        else {
            cout<<min(u,v)<<'\n';
        }
    }
    return 0;
}