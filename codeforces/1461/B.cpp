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
int ara[600][600] , sum[600][600];

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        int n , m;
        cin>>n>>m;


        for(int i =1 ; i <=n ; i++ ) {
            string s;
            cin>>s;
            sum[i][0] = 0;
            for(int j =1; j <=m ; j++ ) {
                if(s[j-1] == '.') ara[i][j] = 0;
                else ara[i][j] = 1;

                sum[i][j] = sum[i][j-1] + ara[i][j];
            }
        }

        ll ans = 0;
        for(int i =1 ; i <=n ; i++ ) {
            for(int j =1 ; j <= m ; j++ ) {

                int tot = 0;

                for(int k = i, col= j , len=1; k <= n && col >= 1 && col + len-1 <= m; k++, col-- , len+=2 ) {
                        
                    if(sum[k][col + len-1] - sum[k][col-1] == len) tot++;
                    else break;
                }
                ans += tot;
                
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}