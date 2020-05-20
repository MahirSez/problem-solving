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
        
        ll n , k;
        cin>>n>>k;
        
        vector<ll>vec;
        map<ll, int>mp;
        
        while(mp[n] == 0 ) {
            mp[n] = 1;
            ll tmp = n;
            vec.push_back(n);
            ll mx = -1 , mn = 11;
            
            while(tmp) {
                mx = max(mx , tmp%10);
                mn = min(mn , tmp%10);
                tmp/=10;
            }
            n += mx*mn;
            
        }
        
//        for(auto x : vec) cout<<x<<" ";
//        cout<<'\n';
        
        if(k > vec.size()) cout<<vec.back()<<'\n';
        else cout<<vec[k-1]<<'\n';
    }
    return 0;
    
}