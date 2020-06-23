#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const ll MOD = 1e9 + 7;
const int MAX = 1e6+ 6;
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        string str;
        cin>>n>>str;
        
        int z = 0;
        for(auto x : str) {
            if(x =='0') z++;
        }
        int last = 0, till = n;
        for(int i = n-1 ; i >=0 ; i--) {
            if(str[i] =='1') {
                last++;
                till = i;
            }
            else break;
        }
        
        
        string ans = "";
        for(int i =0 ; i< till ; i++) {
            char x = str[i];
            if(x =='0') {
                z--;
                ans += x;
            }
            else {
                
                if(z ==0) ans += x;
                else {
                    ans +='0';
                    break;
                }
            }
        }
        while(last--) ans +='1';
        cout<<ans<<'\n';
    }
    return 0;
}