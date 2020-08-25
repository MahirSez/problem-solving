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

const int N = 1e6 + 6;
int main() {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll>vec(n+1) , fre(n+1) , cnt1(n+1) , cnt2(n+1);
        
        for(int i =1 ; i <=n ; i++ ) {
            cin>>vec[i];
        }

        ll ans = 0;

        

        for(int i = 1 ; i + 1 < n ; i++ ) {

            cnt2 = vector<ll>(n+1 , 0);
            cnt1 = vector<ll>(n+1 , 0);


            for(int j = i ; j < n ; j++  ) cnt1[vec[j]]++;
            cnt2[vec[n]]++;

            ll totnow = 0;

            for(int j =1 ; j <=n ; j++ ) {
                totnow += cnt1[j] * cnt2[j];
            }


            for(int j = n-1 ; i + 1 < j ; j--) {
                
                // cout<<" "<<cnt1[2]<<" "<<cnt2[2]<<'\n';
                

                totnow -= cnt1[vec[j]] * cnt2[vec[j]];
                cnt1[vec[j]]--;
                cnt2[vec[j]]++;
                totnow += cnt1[vec[j]] * cnt2[vec[j]];

                if(vec[i] == vec[j]) {

                    ll tmp = totnow - cnt1[vec[j]] * cnt2[vec[j]];
                    tmp += (cnt1[vec[j]]-1) * (cnt2[vec[j]] -1 );

                    ans += tmp;
                }
                // cout<<i<<" "<<j<<" "<<ans<<'\n';
            }
            

            totnow -= cnt1[vec[i]] * cnt2[vec[i]];
            cnt1[vec[i]]--;
            totnow += cnt1[vec[i]] * cnt2[vec[i]];
        }
        cout<<ans<<'\n';
    }
    return 0;
}

/*
 * 
1
5
2 2 2 2 2
*/