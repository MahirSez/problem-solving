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
    
    ll now = 0 , h = 1;
    vector<ll>vec;
    while(now < INF) {
        now += 3*h-1;
        vec.push_back(now);
        h++;
    }
    int t;
    cin>>t;
    while(t-- ) {
        
        ll n;
        cin>>n;
        int ans = 0;
        while(n > 1) {
            
            int id = upper_bound(vec.begin() , vec.end() , n) - vec.begin() -1;
            n -= vec[id];
            ans++;
        }
        cout<<ans<<'\n';
        
    }
    return 0;
    
}