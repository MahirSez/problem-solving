#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;

    vector<int>ara(6);
    for(int i =0 ; i < 6 ; i++ ) cin>>ara[i];
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i =0 ; i < n ; i++ ) cin>>vec[i];

    vector<pii>tmp;

    for(int i =0 ; i < 6 ; i++ ) {
        for(int j =0 ; j < n ; j++ ) tmp.push_back({vec[j] - ara[i], j});
    }
    sort(tmp.begin() , tmp.end());

    ll ans = INF;
    int l = 0 ;
    vector<int>taken(n);
    int now = 0;

    for(int r = 0 ; r < tmp.size() ; r++ ) {
        int id = tmp[r].vv;
        taken[id]++;
        if(taken[id] == 1) now++;
        if(now == n ) {

            while(l<r) {
                int idd = tmp[l].vv;
                if(taken[idd] == 1) break;
                else taken[idd]--;
                l++;
            }

            ans = min(ans , 1LL*(tmp[r].uu - tmp[l].uu) );
        }
    }

    cout<<ans<<'\n';
    
   
    return 0;

    
}