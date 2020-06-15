#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
const int MAXL = 1e5 + 5;
const int TILL = (1<<9);

ll val[MAX], wt[MAX];
ll dp[TILL + 5][MAXL];

vector<int>sml[MAX],  big[MAX];

int main()
{
    fastRead;
    int n;
    cin>>n;

    for(int i = 1 ; i <=n ; i++ ) cin>>val[i]>>wt[i];
    
    for(int i = 1 ; i <=n ; i++ ) {
        
        int tmp = i;
        while(tmp> TILL) {
            big[i].push_back(tmp);
            tmp/=2;
        }
        while(tmp) {
            sml[i].push_back(tmp);
            tmp/=2;
        }
    }
    
    
    for(int i =1 ; i <= min(n,TILL) ; i++) {

        for(int j = 0 ; j < MAXL ; j++ ) {
            
            dp[i][j] = dp[i/2][j];
            
            if(wt[i] <= j) dp[i][j] = max(dp[i][j], dp[i/2][j - wt[i]] + val[i] );
        }
    }
    
    int q;
    cin>>q;
    while(q--) {
        int v, l;
        cin>>v>>l;
        if(v <=TILL) {
            cout<<dp[v][l]<<'\n';
            continue;
        }
            
        
        int nn = big[v].size();
        ll ans = 0;
        
        for(int mask = 0 ; mask < (1<<nn ) ; mask++ )  {
        
            ll prof = 0;
            ll totW = 0;
            for(int j =0 ; j < nn ; j++ ) {
                if(mask & (1<<j)) {
                    prof += val[big[v][j]];
                    totW += wt[big[v][j]];
                }
            }
            if(totW > l) continue;
            int baki = l - totW;
            
            ans = max(ans, prof + dp[ sml[v][0] ][baki]);
        }
        cout<<ans<<'\n';
    }

    return 0;
}
