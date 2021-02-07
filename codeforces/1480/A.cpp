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
        for(int i =0; i < s.size() ;i++ ) {
            if(i%2 == 0) {
                if(s[i] == 'a') s[i] = 'b';
                else s[i] = 'a';
            }
            else {
                if(s[i] == 'z') s[i] = 'y';
                else s[i] = 'z';
            }
        }
        cout<<s<<'\n';
    }
    return 0;

}