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
        ll n , m , x , y;
        cin>>n>>m>>x>>y;
        y = min(y , 2*x);
        
        ll ans = 0;
        
        for(int i =0 ; i < n ; i++ ) {
            string str;
            cin>>str;
            str += '*';
            
            int now = 0;
            
            for(auto xx : str) {
                if(xx == '*') {
                    ans += (now/2)*y;
                    if(now&1) ans += x;
                    now = 0;
                }
                else now++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
    
}