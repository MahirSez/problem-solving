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
    int n;
    string s;
    cin>>n>>s;

    int frm = -1 , to = -1;

    for(int i =0 ; i < n ; i++ ) {
        frm = i;
        if(s[i] =='W') break;
    }
    for(int i = n-1 ; i >=0 ; i--) {
        to = i;
        if(s[i] == 'R') break;
    }
    if(frm == -1|| to ==-1 || frm >to) {
        cout<<0<<'\n';
        return 0;
    }

    int r = 0 , w = 0;
    for(int i = frm ; i <=to ; i++ ) {
        if(s[i] == 'R') r++;
        else w++;
    }
    int ans = min(w, r);

    // cout<<w<< " "<<r<<'\n';

    int cnt = 0;

    for(int i =0 , j = to ; i <w ; i++, j-- ) {
        if(s[j] == 'R')cnt++;
    }
    // cout<<cnt<<'\n';

    cout<<min(ans, cnt)<<'\n';
    return 0;
}