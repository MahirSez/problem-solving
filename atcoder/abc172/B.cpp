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
    string s, t;
    cin>>s>>t;
    int ans = 0;
    for(int i =0 ; i < s.size() ; i++) {
        if(s[i] != t[i]) ans++;
    }
    cout<<ans<<'\n';
    return 0;
}