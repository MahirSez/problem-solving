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
        string s;
        cin>>s;
        vector<int>vis(n) , deg(n);

        int ans = 0;

        for(int i =0 ; i < n ; i++ ) {
            if(s[i] == 'L') deg[(i-1 +n)%n]++;
            else deg[(i+1)%n]++;
        }
        for(int i =0 ; i < n ; i++ ) {
            if(s[i] == 'R' && s[(i+1)%n] == 'L') {
                vis[i] = 5;
                vis[(i+1)%n] = 5;
            }
        }

        for(int i =0 ; i < n ; i++ ) {
            if(deg[i] || vis[i]) continue;

            int cnt = 0, now = i;

            while(vis[now] == 0) {
                vis[now] = 1;
                cnt++;
                if(s[now] =='L') now = (now-1+n)%n;
                else now = (now + 1)%n;
            }
            
            // cout<<" "<<cnt<<'\n';
            cnt--;
            if(cnt ==0) continue;
            ans += (cnt-1)/3 + 1;
        }

        for(int i =0 ; i < n ; i++ ) {
            if(vis[i]) continue;

            int now = i , cnt = 0;
            while(vis[now] == 0) {
                cnt++;
                vis[now] = 1;
                if(s[now] =='L') now = (now-1+n)%n;
                else now = (now + 1)%n;
            }

            assert(cnt >= 3) ;
            ans += (cnt-1)/3 + 1;
        }
        cout<<ans<<'\n';

    }
    return 0;
}