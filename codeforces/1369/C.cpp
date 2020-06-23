#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const ll MOD = 1e9 + 7;
const int MAX = 1e6+ 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<ll>nums(n), lagbe(k), rec(k);
        for(ll& x: nums) cin>>x;
        for(ll& x: lagbe) cin>>x;
        
        sort(nums.begin(), nums.end());
        sort(lagbe.rbegin(), lagbe.rend());
        
        ll ans = 0;
        
        for(int i =0 , j = n-1; i < k ; i++ , j--) {
            rec[k-i-1] = nums[j];
            ans += nums[j];
        }
        
//        for(auto x : rec) cout<<x<<" ";
//        cout<<'\n';
        
        int now = 0;
        
        for(int i =0 ; i < k ; i++ ) {
            
            if(lagbe[i] == 1) {
                ans += rec[i];
                continue;
            }
            ll tgt = lagbe[i]-1;
//            cout<<i<<" "<<now<<" "<<nums[now]<<'\n';
            ans += nums[now];
            while(tgt--) now++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}