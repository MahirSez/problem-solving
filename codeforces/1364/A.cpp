#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n,x;
        cin>>n>>x;
        vector<int>vec(n+1), sum(n+2);
        for(int i =1 ; i <= n ; i++ ) {
            cin>>vec[i];
            sum[i] += vec[i] + sum[i-1];
            sum[i] %= x;
        }
        int ans = 0;
        for(int i = n ; i >=1 ; i--) {
            if(sum[i]) {
                ans = i;
                break;
            }
        }
        
        for(int i = n ; i >=1 ; i--) {
            sum[i] = sum[i+1] + vec[i];
            sum[i] %= x;
        }
        
        for(int i = 1 ; i <=n ; i++ ) {
            if(sum[i]) {
                ans = max(ans, n - i + 1);
            }
        }
        if(ans == 0 ) cout<<-1<<'\n';
        else cout<<ans<<'\n';
    }
    return 0;
}
