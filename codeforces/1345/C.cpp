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
        
        int n;
        cin>>n;
        vector<int>vec(n) , taken(n);
        bool ok = 1;
        for(int i = 0 ; i < n ; i++ ) {
            
            ll tmp;
            cin>>tmp;
            ll now = (i + tmp )%n;
            if(now < 0) now += n;
            assert(now < n);
            if(taken[now]) ok = 0;
            taken[now] = 1;
            
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    return 0;
    
}