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
int last[MAX][5];
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        string s;
        cin>>s;
        int n = s.size();
        for(int i = 0 ; i <=n ; i++ ) {
            last[i][1] = -1;
            last[i][2] = -1;
            last[i][3] = -1;
        }
        
        for(int i =0 ; i < n ; i++ ) {
            int id = s[i]-'0';
            
            last[i][id] = i;
        }
        
        for(int i =1 ; i < n ;i++ ) {
            
            for(int j = 1 ; j <=3 ; j++ ) {
                if(last[i][j] == i) continue;
                last[i][j] = last[i-1][j];
            }
        }
        
//        for(int i =0 ; i < n ;i++) {
//            cout<<last[i][2]<<" ";
//        }
//        cout<<'\n';
        int ans = INF;
        
        for(int i =0 ; i < n ; i++ ) {
            
            int mn = n;
            for(int j =1 ; j <= 3 ; j++ ) {
                mn = min(mn , last[i][j]);
            }
            if(mn == -1) continue;
            ans = min(ans ,  i - mn + 1);
        }
        if(ans == INF) cout<<0<<'\n';
        else cout<<ans<<'\n';
    }
    return 0;
    
}