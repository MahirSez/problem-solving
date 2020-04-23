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
        
        int n , a , b , c , d;
        cin>>n>>a>>b>>c>>d;
        
        int mn = (a-b)*n;
        int mx = (a+b)*n;
        
        int lo = c-d;
        int hi = c+d;
        
        if(mn > hi || mx < lo) {
            cout<<"No\n";
        }
        else cout<<"Yes\n";
        
        
    }
    return 0;
    
    
    
}