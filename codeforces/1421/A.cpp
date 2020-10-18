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
        int a , b;
        cin>>a>>b;
        int ans = 0;

        for(int i =31 ; i>=0 ; i-- ) {
            int x = (a & (1<<i) );
            x = (x !=0);
            int y = (b & (1<<i) );
            y = (y != 0);
            if(x + y == 1) ans |= (1<<i);
        }
        cout<<ans<<'\n';
    }
    return 0;
    
}