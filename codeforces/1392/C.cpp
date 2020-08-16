#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define plp         pair<ll,pll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t-- ) {
        int n;
        cin>>n;
        vector<ll>vec(n+1) , vis(n+1);
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        vec[n] = INF +5;
        priority_queue<plp, vector<plp> , greater<plp> > pq;


        for(int i = 1; i < n ;i++ ) {
            pq.push({vec[i] , {i,i}});
        }

        ll ans = 0;
        while(!pq.empty()) {
            plp tmp = pq.top();
            ll val = tmp.uu;
            ll frm = tmp.vv.uu;
            ll to = tmp.vv.vv;
            pq.pop();

            if(frm == 0 || to == n) continue;
            if(frm == to) {
                if(vis[frm]) continue;
                vis[frm] = vis[to] = 1;
            }

            // cout<<" "<<val<<" "<<frm<<" "<<to<<'\n';

            if(val >= vec[frm-1]) continue;

            if(vec[frm-1] < vec[to+1]) {
                ans += vec[frm-1] - val;
                vis[frm-1] = 1;

                // cout<<" -> "<<vec[frm-1]<<" "<<frm-1<<" "<<to<<'\n';
                pq.push({vec[frm-1] , {frm-1 , to}});
            }
            else{
                ans += vec[to+1] - val;
                vis[to+1] = 1;

                // cout<<" -> "<<vec[to+1]<<" "<<frm<<" "<<to+1<<'\n';
                pq.push({vec[to+1] , {frm , to+1}});
            }

        }

        cout<<ans<<'\n';
        
    }
    return 0;
}