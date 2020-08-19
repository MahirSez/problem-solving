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

const ll N = 1e7 + 6;

int main()  {
    fastio;
    int n , m;
    cin>>n>>m;

    vector<int>ara(n+1) , sum(n+1);
    for(int i =1;  i <=n ; i++ ) cin>>ara[i];
    for(int i =1 ; i <=n ; i++ ) {
        sum[i] = sum[i-1] + ara[i];
    }

    vector<int>vec(m);
    for(int i =0 ; i < m ; i++ ) {
        int l , r;
        cin>>l>>r;
        vec[i] = sum[r] - sum[l-1];
    }

    sort(vec.begin() , vec.end());
    ll ans = 0;
    for(auto x : vec) {
        ans += max(x , 0);
    }

    cout<<ans<<'\n';
    return 0;




}