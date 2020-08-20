#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int N = 2e5 + 6;

int sum[N][2];

int main() {
    fastio;
    int n;
    cin>>n;
    vector<int>vec(n+1);
    for(int i = 1; i <=n ; i++ ) cin>>vec[i];

    int now = 1;
    vector<int>ans;
    for(int i =1 ; i <=n ; i++ ) {
        if(vec[i] == now) {
            ans.push_back(i);
            now++;
        }
    }

    cout<<ans.size()<<'\n';
    for(auto x : ans) cout<<x+2000<<" ";
    cout<<'\n';

    return 0;

}