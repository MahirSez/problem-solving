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
int main() {
    fastio;
    int t;
    cin>>t;
    string f = "First";
    string s = "Second";
    while(t--) {
        int n;
        cin>>n;
        map<int,int>mp;
        for(int i =0 ; i < n  ;i++ ) {
            int tmp;
            cin>>tmp;
            mp[tmp]++;
        }

        if(n%2) {
            cout<<s<<'\n';
            continue;
        }

        int ok = 0;
        for(auto x : mp) {
            if(x.vv%2) ok = 1;
        }
        if(ok) cout<<f<<'\n';
        else cout<<s<<'\n';
    }
    return 0;
}