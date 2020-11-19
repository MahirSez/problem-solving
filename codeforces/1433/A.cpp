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

    vector<int>sum(5);
    sum[1] = 1;
    sum[2] = 3;
    sum[3] = 6;
    sum[4] = 10;

    int t;
    cin>>t;
    
    while(t--) {

        int n;
        cin>>n;
        int id = n%10 - 1;
        int ans = id*10;
        int cnt = 0;
        while(n) {
            cnt++;
            n/=10;
        }
        ans += sum[cnt];
        cout<<ans<<'\n';
    }
    return 0;
}