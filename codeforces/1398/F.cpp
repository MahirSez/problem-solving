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

int sum[N][3] ,prv[N][3];

int main()  {
    // fastio;
    int n;
    string s;
    cin>>n>>s;

    s = '*' + s;

    prv[0][0] = prv[0][1] = -1;

    for(int i =1 ; i <=n ; i++ ) {

        sum[i][0] = sum[i-1][0];
        sum[i][1] = sum[i-1][1];

        prv[i][0] = prv[i-1][0];
        prv[i][1] = prv[i-1][1];

        if(s[i] == '1') {
            sum[i][1]++;
            prv[i][1] = i;
        }
        if(s[i] == '0') {
            sum[i][0] ++;
            prv[i][0] = i;
        }
    }

    // for(int i =1 ; i <=n  ;i++ ) {
    //     cout<<i<<" -- "<<sum[i][0]<<" "<<sum[i][1]<<" -- "<<prv[i][0]<<" "<<prv[i][1]<<'\n';
    // }
    // return 0;

    for(int len = 1 ; len <= n ; len ++ ) {

        
        int now = 1;
        int cnt = 0;

        while(now + len -1 <= n) {
            

            // cout<<len<<" "<<now<<'\n';
            if(sum[now+len-1][1] - sum[now-1][1] == 0  || sum[now + len-1][0] - sum[now-1][0] == 0) {
                cnt++;
                now += len;
                continue;
            }
            
            now = min(prv[now + len-1][0] , prv[now + len-1][1]) + 1;
        }

        cout<<cnt<<" ";
    }

    cout<<'\n';
}