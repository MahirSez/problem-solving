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
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i =0 ; i < n ; i++) cin>>vec[i];
        int ans = 0;
        
        for(auto x : vec) {
            
            int l = 0 , sum = vec[0] ;
            bool ok = 0;
            
            for(int r = 1; r < n ; r++) {
                
                sum += vec[r];
                    
                while(l < r && sum > x) {
                    sum -= vec[l++];
                }
                
                if(l < r && sum == x) ok = 1;
            }
            
            if(ok) ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}