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
        int one = 0 , zero = 0;
        for(auto x : str) {
            if(x == '1') one = 1;
            if(x == '0') zero =1;
        }
        
        if(one + zero == 1) {
            cout<<str<<'\n';
            continue;
        }
        
        int now = 0;
        for(auto xx : str) {
            int x = xx-'0';
        
            if(x == now) {
                cout<<x;
                now^=1;
            }
            else cout<<now<<x;
        }
        if(now == 1) cout<<now;
        cout<<'\n';
    }
    return 0;
    
}