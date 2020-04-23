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
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n ;
        cin>>n;
        vector<int>pos(n+1) , vec(n+1);
        
        for(int i= 1; i <= n ; i++) {
            cin>>vec[i];
            pos[vec[i]] = i;
        }
        
        int now = 1 , till = n+1;
        
        bool ok =1;
        while(now <= n && ok) {
            
            int frm = pos[now];
            
            int to = till -1;
            
            for(int i = frm ; i <=to ; i++ ) {
                
                if(vec[i] != now) {
                    ok = 0;
                    break;
                }
                
                now++;
            }
            till = frm;
        }
        
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}