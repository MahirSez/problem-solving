#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n , m , k;
        cin>>n>>m>>k;
        
        vector<int>ara(n);
        
        
        for(int i =0 ; i < n ;i++ ) cin>>ara[i];
        
        k = min(k , m-1);
        int ans = 0;
        
        for(int i =0 ; i <= k ; i++ ) {
            
            int ff = i;
            
            int tmp = k - i;
            int lll = n - tmp - 1;
            
            int baki = m - k - 1;
            int tmpAns = INF;
            
            for(int j = 0 ; j <= baki ; j++ ) {
                
                int lEnd =  ff + j;
                int ttmp = baki - j;
                
                int rEnd =  lll - ttmp ;
                
                tmpAns = min(tmpAns , max(ara[lEnd ], ara[rEnd]) ) ;
            }
            
            ans = max(ans , tmpAns);
            
        }
        cout<<ans<<'\n';
    }
    return 0;
}