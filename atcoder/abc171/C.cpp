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
    ll x;
    cin>>x;
    string s = "";
    while(x) {
        int tmp = ( x%26 -1 + 26)%26;
        s += char('a' + tmp);
        if(x%26 == 0 ) x = x/26 - 1;
        else x /= 26;
    }
    reverse(s.begin() , s.end());
    cout<<s<<'\n';
    return 0;
}