#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pip         pair<int, pii >
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n;
        cin>>n;
        string str;
        cin>>str;
        int sum = 0;
        vector<int>vec;
        
        for(auto x : str) {
            if( (x-'0') %2) vec.push_back(x-'0');
        }
        
        if(vec.size() > 1) cout<<vec[0]<<vec[1]<<'\n';
        else cout<<-1<<'\n';
        
        
    }
    return 0;
    
}