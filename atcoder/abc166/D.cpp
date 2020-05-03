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

ll get(ll x) {
    
    return x*x*x*x*x;
}
int main()
{
    fastRead;
    ll x;
    cin>>x;
    
    
    for(ll i = -8191; i <=8191; i++ ) {
        
        for(int j = -8191 ; j <= 8191 ; j++ ) {
            
            if(get(i) - get(j) ==x ) {
                cout<<i<<" "<<j<<'\n';
                return 0;
            }
        }
    }
    return 0;
    
}