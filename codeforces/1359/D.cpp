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
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i =0 ; i < n ; i++ ) cin>>vec[i];
    
    int ans = 0;
    
    for(int i = 1 ; i <= 30 ; i++ ) {
        
        
        vector<int>tmp = vec;
        for(auto &x : tmp) {
            if(x > i) x = -INF;
        }
        int mx = 0 , now = 0;
        
//        cout<<i<<" ->\n";
//        for(auto x : tmp) cout<<x<<" ";
//        cout<<'\n';
        
        for(auto x : tmp) {
            now += x;
            mx = max(mx , now);
            now = max(0 , now);
        }
        
        ans = max(ans , mx-i);
        
        for(auto &x : tmp) {
            if(x == -INF) x = i;
        }
    }
    cout<<ans<<'\n';
    return 0;
}