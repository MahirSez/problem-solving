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
        ll _01 , _11 , _21;
        ll _02 , _12 , _22;
        cin>>_01>>_11>>_21;
        cin>>_02>>_12>>_22;


        ll ans = min(_21 , _12);


        ll tmp = min(_11 , _02);
        _11 -= tmp;
        tmp = min(_01 , _22);
        _22 -= tmp;

        ans -= min(_11 , _22);

        
        cout<<2LL*ans<<'\n';
    }
    return 0;
}