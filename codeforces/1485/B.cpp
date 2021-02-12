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
    
    int n, q , k;
    cin>>n>>q>>k;

    vector<ll>vec(n+1), sum(n+1);

    for(int i = 1; i <=n ; i++ ) cin>>vec[i];

    for(int i = 2 ; i < n ; i++ ) {
        sum[i] = vec[i+1] - vec[i-1] - 2;
        sum[i] += sum[i-1];
    }
    

    while(q--) {
        int l, r;
        cin>>l>>r;
        if(l == r) {
            cout<<k-1<<'\n';
            continue;
        }
        ll val1 = vec[l+1]-2;
        ll val2 = k - vec[r-1] - 1;
        ll val3 = 0;
        if(l + 1 != r) {
            val3 = sum[r-1] - sum[l];
        }
        cout<<val1 + val2 + val3<<'\n';
    }
    return 0;
}