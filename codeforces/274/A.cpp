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

    ll n , k;
    cin>>n>>k;
    vector<ll>vec(n);
    map<ll,int>mark;
    for(int  i =0 ; i < n ; i++ ) cin>>vec[i];
    sort(vec.begin() , vec.end());

    int ans = 0;

    for(auto x : vec) {
        if(mark[x]) continue;
        ans++;
        mark[k*x] = 1;
    }

    cout<<ans<<'\n';
    return 0;

    
    
}