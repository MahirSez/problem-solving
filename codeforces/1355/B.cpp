#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 2e5 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>rec(n+1);
        for(int i =0 ; i < n ; i++ ) {
            int tmp;
            cin>>tmp;
            rec[tmp]++;
        }
        ll ans = 0 ;
        for(int i = 1 ; i <=n ; i++ ) {
            
            if(i> 1) rec[i] += rec[i-1]%(i-1);
            
            ans+= rec[i]/i;
            
        }
        cout<<ans<<'\n';
    }
    return 0;
    
}