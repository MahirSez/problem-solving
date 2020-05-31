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
        string str;
        cin>>str;
        int n = str.size();
        int o =  0 , z = 0;
        for(auto x : str) {
            if( x == '0') z++;
            else o++;
        }
        int ans = min(o , z);
        
        int oflip = o;
        int zflip = 0;
        for(auto x : str) {
            
            if(x == '0') zflip++;
            else oflip--;
            ans = min(ans , zflip + oflip);
        }
        
        oflip = o;
        zflip = 0;
        reverse(str.begin() , str.end());
        for(auto x : str) {
            
            if(x == '0') zflip++;
            else oflip--;
            ans = min(ans , zflip + oflip);
        }        
        
        cout<<ans<<'\n';
    }
    return 0;
}