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
        ll n;
        cin>>n;

        vector<ll>ans;
        ans.push_back(n);

        for(ll i = 2 ; i*i <= n ; i++ ) {
            
            ll nn = n;

            vector<ll>tmp;
            while(nn % i == 0) {
                tmp.push_back(i);
                nn /= i;
            }
            if(tmp.size() == 0) continue;
            tmp.back() *= nn;


            if(tmp.size() > ans.size()) ans = tmp;
        }

        cout<<ans.size()<<'\n';
        for(auto x : ans) cout<<x<<" ";
        cout<<'\n';
        
    }
    return 0;
}