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
        string s;
        cin>>s;
        int n = s.size();
        if(n%2) {
            cout<<"NO\n";
            continue;
        }
        if(s[0] == ')' || s[n-1] == '(') cout<<"NO\n";
        else cout<<"YES\n";
    }  
    return 0;
}