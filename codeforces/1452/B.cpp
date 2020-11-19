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
        int n;
        cin>>n;
        vector<int>vec(n), vec1;
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        sort(vec.rbegin() , vec.rend());
        int mx1 = vec[0] , mx2 = vec[1];
        // cout<<mx1<<" "<<mx2<<'\n';

        ll tot1 = 0 , tot2 = 0;
        for(auto x : vec) {
            tot1 += mx1 - x;
            if(x <= mx2) tot2 += mx2 - x;
        }
        ll ans = 0;
        // cout<<tot1<<" "<<tot2<<'\n';

        for(auto x : vec) {
            ll tmp;

            if(x == mx1) {

                if(tot2 >= x) {
                    tmp = tot2 - mx2;
                }
                else {

                    ll tmp2 = (x - tot2)%(n-1);
                    if(tmp2) tmp = (n-1 - tmp2);
                    else tmp= 0;
                }

            }
            else {    
                ll str = tot1;
                tot1 -= (mx1 - x);
                
                if(tot1 >= x) {
                    tmp = tot1 - x;
                }
                else {
                    ll tmp1 = (x - tot1)%(n-1);
                    if(tmp1) tmp = (n-1 - tmp1);
                    else tmp = 0;
                }

                tot1 = str;
                
            }
      
            // cout<<" "<<tmp<<'\n';
            ans = max(ans ,tmp);
        }
        cout<<ans<<'\n';
    }
    return 0;
}