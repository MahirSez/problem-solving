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

    int n, m;
    cin>>n>>m;
    string s, t;
    cin>>s>>t;
    vector<int>fst(m) , lst(m);

    int j = 0;
    for(int i = 0; i < m ; i++) {
        while(j < n && t[i] != s[j]) j++;
        assert(j < n);
        fst[i] = j++;
    }
    j = n-1;
    for(int i = m-1; i >=0 ; i--) {
        while( j>=0 && t[i] != s[j]) j--;
        assert( j>= 0);
        lst[i] = j--;
    }

    // for(auto x : fst) cout<<x<<" ";
    // cout<<'\n';
    // for(auto x : lst) cout<<x<<" ";
    // cout<<'\n';


    int ans = 0;

    for(int i =1 ; i < m ; i++ ) {
        ans = max(ans, lst[i] - fst[i-1]);
    }
    cout<<ans<<'\n';
    return 0;
}