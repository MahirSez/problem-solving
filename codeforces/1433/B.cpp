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
    while(t--)   {
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        int frm = n-1, to = 0;
        for(int i =0 ; i < n ; i++ ) {
            if(vec[i] == 1) {
                frm = i;
                break;
            }
        }
        for(int i = n-1 ; i >=0 ; i-- ) {
            if(vec[i] == 1) {
                to = i;
                break;
            }
        }
        int ans = 0;
        for(int i = frm ; i <=to ; i++ ) ans += vec[i] == 0;
        cout<<ans<<'\n';
    }
    return 0;
}