#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
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
        
        int a , b , c;
        
        cin>>a>>b>>c;
        
        
        int mn = min(c/2 , b);
        int ans = mn + 2*mn;
       
        b-=mn;
        c-=mn;
        
        
        mn = min(b/2 , a);
        
        ans += mn*3;
        cout<<ans<<'\n';
        
        
    }
    
    return 0;
    
}