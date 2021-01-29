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

    int t;
    cin>>t;
    while(t--) {
        ll n, k;
        cin>>n>>k;
        vector<ll>vec(n);
        for(int i =0; i< n; i++ ) cin>>vec[i];

        ll lo = 0, hi = 1e16 , ret = -1;

        while(lo <= hi) {
            ll mid = (hi + lo)/2;

            ll sum = mid + vec[0];

            int ok = 1;
            for(int i =1 ; i < n; i++ ) {

                if( 1LL*vec[i]*100 > 1LL*sum * k) {
                    ok = 0;
                }
                sum += vec[i];
            }

            // cout<<mid<<" "<<ok<<'\n';
            if(ok) {
                ret = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        // assert(ret != -1);
        cout<<ret<<'\n';
    }
    return 0;
}