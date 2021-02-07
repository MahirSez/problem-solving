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

    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i =0; i <n ; i++ )cin>>vec[i];
    vector<int>v1, v2;
    v1.push_back(-1);
    v2.push_back(-1);

    int ans = 0;

    for(int i =0; i< n; i++ ) {
        
        if(vec[i] == v1.back() && vec[i] == v2.back()) continue;
        if(vec[i] == v1.back() && vec[i] != v2.back()) {
            v2.push_back(vec[i]);
            ans++;
        }
        else if(vec[i] == v2.back() && vec[i] != v1.back()) {
            v1.push_back(vec[i]);
            ans++;
        }
        else if( i < n -1 && vec[i] != vec[i+1]) {
            ans++;
            if(v1.back() == vec[i+1]) v1.push_back(vec[i]);
            else v2.push_back(vec[i]);
        }
        else {
            v1.push_back(vec[i]);
            ans++;
        }

        
        // for(auto x : v1) cout<<x<<" ";
        // cout<<'\n';
        //     for(auto x : v2) cout<<x<<" ";
        // cout<<'\n';
        // cout<<'\n';
    }

    // for(auto x : v1) cout<<x<<" ";
    // cout<<'\n';
    //     for(auto x : v2) cout<<x<<" ";
    // cout<<'\n';
    cout<<ans<<'\n';
    return 0;
}