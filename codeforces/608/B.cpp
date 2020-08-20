#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int N = 2e5 + 6;

int sum[N][2];

int main() {
    fastio;
    string s1 , s2;
    cin>>s1>>s2;
    int n1 = s1.size();
    int n2 = s2.size();
    s1 = '*' + s1;
    s2 = '*' + s2;
    for(int i =1 ; i <= n2 ; i++ ) {
        sum[i][0] = sum[i-1][0];
        sum[i][1] = sum[i-1][1];
        sum[i][s2[i]-'0']++;

    }
    ll ans = 0;
    for(int i =1 ; i <=n1  ; i++ ) {
        int frm = i , to = n2 - (n1 - i);
        int one = sum[to][1] - sum[frm-1][1];
        int z = sum[to][0] - sum[frm-1][0];

        if(s1[i] == '1') ans += z;
        else ans += one;

    }
    cout<<ans<<'\n';
    return 0;

}