#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        int xx, yy;
        cin>>xx>>yy;
        int u = 0, d = 0 , l = 0 , r = 0;
        string s;
        cin>>s;
        for(auto x : s) {
            if(x == 'U') u++;
            if(x == 'L') l++;
            if(x == 'R') r++;
            if(x == 'D') d++;
        }
        int ok1 = 0 , ok2 = 0;
        if(xx <= 0 && l >= abs(xx))  ok1 = 1;
        else if(xx > 0 && r >= abs(xx)) ok1 = 1;

        if(yy <=0 && d >= abs(yy)) ok2 = 1;
        else if(yy > 0 && u >= abs(yy)) ok2 = 1;

        if(ok1 && ok2 ) cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}