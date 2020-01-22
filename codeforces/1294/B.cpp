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
        
        int n;
        cin>>n;
        int x = 0 , y = 0;
        bool ok = 1;
        vector<pii>xx(n) ;
        for(int i =0 ; i < n ; i++ ) cin>>xx[i].uu>>xx[i].vv;
        sort(xx.begin() , xx.end());
        
        string ret = "";
        for(auto p : xx) {
            
            int tx= p.uu;
            int ty = p.vv;
            
            if(x > tx || y > ty) ok = 0;
            
            while(x < tx) {
                ret += "R";
                x++;
            }
            
            while( y < ty) {
                ret += "U";
                y++;
            }
            
            
            
            
            
            x = tx;
            y = ty;
        }
        if(!ok) cout<<"NO\n";
        else {
            cout<<"YES\n";
            cout<<ret<<'\n';
        }
    }
    return 0;
}


/*

RUUURRRRUU
RRURUUURRU
*/