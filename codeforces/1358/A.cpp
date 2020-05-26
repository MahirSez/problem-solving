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
        int n , m;
        cin>>n>>m;
        int ans1 = n *(m/2);
        if(m%2) ans1 += n/2 + (n%2);
        
        swap(n,m);
        
        int ans2 = n *(m/2);
        if(m%2) ans2 += n/2 + (n%2);
            
        
        cout<<min(ans1 , ans2)<<'\n';
    }
    
}