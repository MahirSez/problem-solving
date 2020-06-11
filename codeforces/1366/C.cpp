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

int ara[40][40], rec[40][40];

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n, m;
        cin>>n>>m;
        memset(ara, 0 , sizeof ara);
        
        for(int i =1 ; i <=n ; i++ ) {
            for(int j = 1; j <=m ; j++) {
                cin>>ara[i][j];
            }
        }
        
        for(int i =1 ; i <=n ; i++ ) {
            for(int j =1 ; j <=m ; j++ ) {
                
                int d1 = abs(i-1) + abs(j-1);
                int d2 = abs(n-i) + abs(m-j);
                
                rec[i][j] = min(d1, d2);
            }
        }
        
        int tot = n + m -2;
        if(tot&1) tot++;
        int ans= 0;
        for(int i = 0 ; i < tot/2 ; i++)  {
            
            int one = 0, zero = 0;
            for(int j = 1; j <=n ; j++ ) {
                for(int k =1 ; k<=m ; k++) {
                    if(rec[j][k] != i) continue;
                    if(ara[j][k]) one++;
                    else zero++;
                }
            }
            ans +=min(one, zero);
        }
        cout<<ans<<'\n';
        
    }
    return 0;
}