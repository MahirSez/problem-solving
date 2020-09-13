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

    
    int n;
    cin>>n;
    vector<ll>x(n) , y(n);
    for(int  i=0 ; i < n ; i++ ) cin>>x[i]>>y[i];

    ll mnSum = INF, mxSum = -INF;
    for(int i =0 ; i < n ; i++ ) {
        mnSum = min(mnSum , x[i] + y[i]);
        mxSum = max(mxSum , x[i] + y[i]);
    }

    ll ans1 = mxSum - mnSum;

    ll mnDiff = INF , mxDiff = -INF;
    for(int i =0 ; i < n ; i++ ) {
        mnDiff = min(mnDiff , x[i] - y[i]);
        mxDiff = max(mxDiff , x[i] - y[i]);
    }

    ll ans2 = mxDiff - mnDiff;
    cout<<max(ans1 , ans2)<<'\n';
    return 0;


}