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
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>vec(2*n), rec(n+1);
        for(int i =0 ; i < 2*n ; i++ ) cin>>vec[i];
        vector<int>ans;
        for(auto x : vec) {
            if(rec[x]) continue;
            rec[x] = 1;
            ans.push_back(x);
        }
        for(auto x : ans) cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
    
}