#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 998244353 ;

const int N = 1e6 + 6;

int main()  {
    fastio;
    int n;
    cin>>n;
    vector<int>vec(n+1);
    ll ret = 1;
    map<int,int>mp;

    for(int i =1 ; i <= n ; i ++  ) {
        cin>>vec[i];
        mp[vec[i]] = i;
    }

    int last = mp[vec[1]];
    for(int i =1 ; i <=n ; i++ ) {
        if(i > last) ret = (ret *2)%MOD;
        last =max(last , mp[vec[i]]);
    }
    cout<<ret<<'\n';
    return 0;
}