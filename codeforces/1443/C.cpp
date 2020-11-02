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

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll>a(n) , b(n);
        for(int i = 0 ; i < n ; i++ ) cin>>a[i];
        for(int i = 0 ; i < n ; i++ ) cin>>b[i];

        ll lo = 0 , hi = 1e16 , ret = -1;
        while(lo <=hi) {
            ll mid = (lo+hi)/2;

            ll tot = 0;
            for(int i =0 ; i < n ; i++) {
                if(a[i] > mid) tot += b[i];
            }
            if(tot <= mid) {
                hi = mid - 1;
                ret = mid;
            }
            else lo = mid + 1;
        }
        cout<<ret<<'\n';
    }
    return 0;
    
}