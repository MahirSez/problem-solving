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
        ll a , b , c , d;
        cin>>a>>b>>c>>d;
        a -= b;
        if(a <=0) {
            cout<<b<<'\n';
            continue;
        }
        
        if(d >= c) {
            cout<<-1<<'\n';
            continue;
        }
        ll slp = c - d;
        ll tmp = (a-1)/slp + 1;
        ll ans = tmp* c + b;
        cout<<ans<<'\n';
    }
    return 0;
    
}