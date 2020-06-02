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
        int a, b, c;
        cin>>a>>b>>c;
        int ans = 0;
        if(a) {
            a--;
            ans++;
        }
        if(b) {
            b--;
            ans++;
        }
        if(c) {
            c--;
            ans++;
        }
        
        if( c >= a && c >= b) swap(a, c);
        if( b >= a && b >= c) swap(b, c);
        
        if( c >= b) swap(b, c);
        if(a && b) {
            a--;
            b--;
            ans++;
        }
        if(c && b) {
            c--;
            b--;
            ans++;
        }
        if(a && c) {
            a--;
            c--;
            ans++;
        }
        if(b && a && c) {
            ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}