#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;
    int n , xx;
    cin>>n>>xx;

    vector<int>vec(n);
    map<int,int>mp , mp1;
    

    for(auto &x : vec) {
        cin>>x;
        if(mp[x]) {
            cout<<0<<'\n';
            return 0;
        }
        mp[x] = 1;
    }
    int ans = 10;

    for(auto x : vec ) {
        mp[x]--;
        if(mp[x & xx]) ans = min(ans , 1);
        if(mp1[x & xx]) ans = min(ans, 2);

        mp[x]++;
        mp1[x & xx]++;
    }
    if(ans == 10) cout<<-1<<'\n';
    else cout<<ans<<'\n';
    return 0;


    
    
}