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
        ll n, x;
        cin>>n>>x;

        vector<pll>vec(n);
        for(int i= 0; i<n ; i++) cin>>vec[i].uu, vec[i].vv = 1;


        for(int i =0; i< vec.size() ; i++ ) {
            if(vec[i].uu%x) break;


            vec.push_back({vec[i].uu/x, vec[i].vv*x});
        }

        ll tot = 0;
        for(auto x: vec) tot += x.uu * x.vv;

        cout<<tot<<'\n';

    }

    return 0;
}