#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;
    int l = -2e9 , r = 2e9;

    int t;
    cin>>t;
    while(t--) {
        string s;
        int val;
        string res;
        cin>>s>>val>>res;
        if(s == ">=") {
            if(res == "Y") l = max(l, val);
            else r = min(r , val-1);
        }
        if(s == ">") {
            if(res == "Y") l = max(l, val+1);
            else r = min(r , val);
        }
        if(s == "<=") {
            if(res == "Y") r = min(r, val);
            else l = max(l , val + 1);
        }
        if(s == "<") {
            if(res == "Y") r = min(r, val -1);
            else l = max(l , val );
        }
        
    }

    
    if(l <=r) cout<<l<<'\n';
    else cout<<"Impossible\n";
    return 0;
}