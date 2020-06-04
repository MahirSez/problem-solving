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
        ll a , b;
        cin>>a>>b;
        int cnt1= 0 , cnt2 = 0;
        while(a%2 == 0) {
            cnt1++;
            a/=2;
        }
        while(b %2 ==0 ) {
            cnt2++;
            b/=2;
        }
        if(a != b) {
            cout<<-1<<'\n';
            continue;
        }
        ll tot = abs(cnt1-cnt2);
        
//        cout<<tot<<" ";
        
        ll ans = 0;
        
        ll tmp = tot / 3;
        ans += tmp;
        tot -= tmp * 3;
        
        
        tmp = tot/2;
        ans += tmp;
        tot -= tmp * 2;
        
        ans += tot;
        
        cout<<ans<<'\n';
        
    }
    return 0;
    
}
