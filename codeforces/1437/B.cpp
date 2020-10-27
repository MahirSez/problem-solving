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
        int n ;
        string s;
        cin>>n>>s;
        int cnt1 = 0 , cnt2 = 0;
        for(int i = 0 ; i < n-1 ; i++ ) {
            if(s[i] =='0' && s[i+1]=='0') cnt1++;
            if(s[i] =='1' && s[i+1]=='1') cnt2++;
        }
        cout<<max(cnt1,cnt2)<<'\n';
    }
    return 0;
}