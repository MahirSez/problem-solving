#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    
    int t;
    cin>>t;
    while(t--) {
        
        int n, x, m;
        cin>>n>>x>>m;
        vector<pii>vec;
        
        vec.push_back({x,x});
        
        for(int i =0 ; i < m ; i++ ) {
            int u, v;
            cin>>u>>v;
            
            for(auto x : vec) {
                
                if(u > x.vv || v < x.uu ) continue;
                vec.push_back({u,v});
                break;
            }
        }
        
        sort(vec.begin(), vec.end());
        
        int till = 0;
        int ans = 0;
        
        for(auto x : vec) {
            
//            cout<<x.uu<<" "<<x.vv<<'\n';
            if(till >= x.vv) continue;
            
            int frm = max(x.uu, till + 1);
            till = x.vv;
            
            ans += till - frm  +1;
        }
        
        cout<<ans<<'\n';
        
    }
    return 0;
}