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
        
        ll x , y , a , b;
        cin>>x>>y>>a>>b;
        
        ll up = y - x;
        ll down = a+b;
        
        if( (up % down) == 0 && (up/down)>= 0  ) {
            cout<<up/down<<'\n';
        }
        else cout<<-1<<'\n';
    }
    return 0;
    
}