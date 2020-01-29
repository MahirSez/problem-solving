#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n , xx;
        cin>>n>>xx;
        string str;
        cin>>str;
        
        
        int sum = 0;
        
        for(auto x : str) {
            if(x == '0') sum++;
            else sum--;
        }
        
        int tot = 0;
        
        if(sum == 0 ) {
            
            bool ok = 1;
            for(auto x : str) {
                
                if(x == '0') tot ++;
                else tot--;
                
                
                if(tot == xx) ok = 0;
            }
            
            if(!ok) cout<<-1<<'\n';
            else if(xx ==  0) cout<<1<<'\n';
            else cout<<0<<'\n';
            continue;
        }
        
        tot = 0;
        
        int ans = 0;
        
        if(xx == 0 ) ans++;
        
        for(auto x : str) {
            
            if(x == '0') tot ++;
            else tot--;

            
            if( (( (xx-tot) % sum )== 0) && (xx-tot)/sum >= 0  ) ans++;
           
        }
        cout<<ans<<'\n';
        
    }
    return 0;
}
/*
1
5 3
10101
*/