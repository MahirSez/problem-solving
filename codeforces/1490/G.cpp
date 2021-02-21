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
        int n, m;
        cin>>n>>m;
        vector<ll>vec(n);
        vector<pll>sum(n);
        for(int i =0; i < n; i++ ) cin>>vec[i];

        sum[0].uu = vec[0];
        sum[0].vv = 1;
        for(int i =1 ; i < n ; i++ ) {
            sum[i].uu = vec[i] + sum[i-1].uu;
            sum[i].vv = (i+1);
        }
        ll fullsum = sum.back().uu;
        vector<pll>pmaxsum = sum;
        for(int i =1 ; i <n  ;i++ ) {
            if(pmaxsum[i].uu <= pmaxsum[i-1].uu) pmaxsum[i] = pmaxsum[i-1];
        }
        sum = pmaxsum;


        // for(auto x : sum) cout<<x.uu<<" ";
        // cout<<'\n';

        while(m--) {
            ll x;
            cin>>x;

            if(sum.back().uu >= x) {

                auto xx = lower_bound(sum.begin(), sum.end(), pll(x, -1));

                // cout<<(*xx).uu<<" "<<(*xx).vv<<'\n';
                cout<<(*xx).vv-1<<" ";
                continue;
            }
            if(fullsum <= 0) {
                cout<<-1<<' ';
                continue;
            }
            // cout<<" *"<<x<<'\n';

            ll lo = 0, hi = 1e9, ret = -1;
            while(lo <= hi) {
                ll mid = (lo+hi)/2;
                if(mid * fullsum >= x) {
                    ret = mid * n - 1;
                    hi = mid - 1;
                    continue;
                }
                ll baki = x - mid * fullsum;

                if(baki > sum.back().uu ) {
                    lo = mid + 1;
                    continue;
                }

                auto xx = lower_bound(sum.begin(), sum.end(), pll(baki, -1));
                hi = mid - 1;
                ret = mid * n + (*xx).vv - 1;
            }
            cout<<ret<<" ";
        }
        cout<<'\n';
    }
    return 0;

}

/*
1
2 1
2 -1
1
*/