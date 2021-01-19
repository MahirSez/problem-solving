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
        int n, m;
        cin>>n>>m;

        vector<int>pref(n+5);
        vector<int>pmax(n+5), pmin(n+5);
        vector<int>sufmax(n+5), sufmin(n+5);

        string s;
        cin>>s;

        for(int i =1 ; i <= n ; i++ ) {

            int val = s[i-1] == '-' ? -1 : 1;
            pref[i] = pref[i-1] + val;

            pmax[i] = max(pmax[i-1] , pref[i]);
            pmin[i] = min(pmin[i-1] , pref[i]);
        }

        for(int i = n ; i>= 1 ; i--) {

            int val = s[i-1] == '-' ? -1 : 1;
            sufmax[i] = max(0, sufmax[i+1] + val);
            sufmin[i] = min(0, sufmin[i+1] + val);            
        }

        while(m--) {
            int l, r;
            cin>>l>>r;
            l--;
            r++;

            int mx = max( pmax[l] , pref[l] + sufmax[r]);
            int mn = min( pmin[l] , pref[l] + sufmin[r] );

            // cout<<mx<<" "<<mn<<'\n';

            cout<<mx - mn + 1<<'\n';
        }
    }
    return 0;
}

