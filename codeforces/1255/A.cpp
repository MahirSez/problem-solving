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
        ll a , b;
        cin>>a>>b;
        if(a < b) swap(a,b);
        ll diff = a - b;
        
        ll ans = diff/5;
        diff%=5;
        ans += diff/2;
        diff%=2;
        ans += diff;
        cout<<ans<<'\n';
    }
    return 0;
}