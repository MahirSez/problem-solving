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
        int n, k , m;
        cin>>n>>k>>m;
        vector<int>col(n+1);

        for(int i =1 ; i <= m ; i++ ) {
            int val;
            cin>>val;
            col[val] =  2;
        }

        if( (n-m) % (k-1)) {
            cout<<"NO\n";
            continue;
        }
        int cnt = 0;
        int mn = -1, mx = n+1;
        for(int i = 1 ; i<= n ; i++ ) {

            if(col[i]) continue;
            col[i] = 1;
            mn = max(mn, i);
            cnt++;
            if(cnt == (k-1)/2) break;
        }
        cnt = 0;
        for(int i = n ; i >=1 ; i-- ) {
            if(col[i]) continue;
            col[i] = 1;
            mx = min(mx, i);
            cnt++;
            if(cnt == (k-1)/2) break;
        }

        // cout<<mn<<" "<<mx<<'\n';

        int ok = 0;
        for(int i = mn ; i <= mx ;i++ ) {
            if(col[i] == 2)  ok = 1;
        }
        cout<<(ok ? "YES" : "NO")<<'\n';
    }
    return 0;
}    