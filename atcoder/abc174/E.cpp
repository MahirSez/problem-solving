#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pdp         pair<double, pii>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;
    int n, k;
    cin>>n>>k;
    vector<int>vec(n);
    for(int i =0 ; i < n ; i++ ) cin>>vec[i];


    int lo = 1, hi = INF, ret = -1;

    while(lo <=hi) {
        int mid = (lo+hi)/2;

        
        int cnt = 0;

        for(auto x : vec) {
            cnt += (x-1)/mid + 1 -1;
        }

        if(cnt > k) {
            lo = mid + 1;
        }
        else {
            ret = mid;
            hi = mid - 1;
        }

    }
    cout<<ret<<'\n';
    return 0;
}