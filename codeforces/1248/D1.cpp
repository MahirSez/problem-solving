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

    int n;
    cin>>n;
    string s;
    cin>>s;
    int tot = 0;
    for(auto x : s) {
        if(x == '(') tot++;
        else tot--;
    }
    if(tot) {
        cout<<0<<'\n';
        cout<<1<<" "<<1<<'\n';
        return 0;
    }
    int ans = -1;
    int l , r;

    for(int i =0 ; i < n ; i++ ) {
        for(int j = i+ 1 ; j < n ; j++ ) {

            swap(s[i] , s[j]);

            int mn = INF;
            tot = 0;
            int cnt = 0;
            for(auto x : s) {
                if(x == '(') tot++;
                else tot--;

                if(tot < mn) {
                    mn = tot;
                    cnt = 1;
                }
                else if(tot == mn) cnt++;
            }

            // cout<<i<<" "<<j<<" "<<cnt<<'\n';
            if(cnt > ans) {
                ans = cnt;
                l = i +1 ;
                r = j + 1;
            }

            swap(s[i] , s[j]);
        }
    }
    cout<<ans<<'\n';
    cout<<l<<" "<<r<<'\n';
    return 0;
    
}