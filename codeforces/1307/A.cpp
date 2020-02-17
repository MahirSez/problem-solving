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
        
        int n , d;
        cin>>n>>d;
        
        vector<int>vec(n);
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        
        while(d > 0) {
            
            bool ok = 0;
            for(int i = 1 ; i < n ; i++ ) {
                
                if(vec[i] == 0 ) continue;
                
                if(i > d) break;
                
                vec[i]--;
                vec[0]++;
                d-=i;
                ok = 1;
                break;
            }
            if(!ok) break;
        }
        
        cout<<vec[0]<<'\n';
        
    }
    return 0;
    
}