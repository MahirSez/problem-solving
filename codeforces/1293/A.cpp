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

const int MAX = 3e3 + 6;
int main()
{
    fastRead;
    
    int t;
    cin>>t;
    while(t--) {
        
        int n , s , k;
        cin>>n>>s>>k;
        
        map<int,int>mp;
        
        while(k--) {
            int tmp;
            cin>>tmp;
            mp[tmp] = 1;
        }
        
        int ans = -1;
        
        for(int now1 = s , now2 = s ; ; now1++ , now2--) {
            
            if(now1 <=n && mp[now1] ==0)  {
                ans = abs(now1 - s);
                break;
            }
            if(now2 > 0 && mp[now2] ==0)  {
                ans = abs(now2 - s);
                break;
            }
        }
    
        cout<<ans<<'\n';
        
    }
    return 0;
}