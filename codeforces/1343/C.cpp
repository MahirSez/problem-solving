#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

/*
1
10
-2 8 3 8 -4 -15 5 -2 -3 1
*/
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll>vec(n+1);
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        
        ll ans = 0;
        
        int id = 0;
        while(id < n ) {
            
            vector<ll>tmp;
            int sign = (vec[id] <0 ? -1 : 1);
            
            for(int i = id ; ; i++ ) {
                    
                int now = (vec[i]  < 0 ? -1 : 1);
                if( i == n ) now = 0;
                
                if(sign == -1 && now != -1) {
                    id = i;
                    break;
                }
                else if(sign == 1 && now != 1) {
                    id = i;
                    break;
                }
                
                tmp.push_back(vec[i]);
            }
            
            sort(tmp.begin() , tmp.end());
            
//            for(auto x : tmp) cout<<x<<" ";
//            cout<<'\n';
            
            ans += tmp.back();
        }
        
        cout<<ans<<'\n';
    }
    
    
}