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
        
        string str;
        cin>>str;
        int n = str.size();
        int frm = -1 , to = -1;
        for(int i =0 ; i < n ; i++ ) {
            if(str[i] == '1') {
                frm = i;
                break;
            }
        }
        for(int i = n-1 ; i >=0 ; i-- ) {
            if(str[i] == '1') {
                to = i;
                break;
            }
        }        
        if(frm == -1) {
            cout<<0<<'\n';
            continue;
        }
        int ans = 0;
        for(int i = frm ; i<=to ; i++ ) {
            if(str[i] == '0') ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}