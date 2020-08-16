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
    int t;
    cin>>t;
    while(t-- ) {
        int n;
        cin>>n;
        set<int>s;
        for(int i =0 ; i < n ; i++ ) {
            int tmp;
            cin>>tmp;
            s.insert(tmp);
        }
        if(s.size() == 1) cout<<n<<'\n';
        else cout<<1<<'\n';
    }
    return 0;
}