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
    int a, b, v, w, t;
    cin>>a>>v>>b>>w>>t;
    
    if(a==b) {
        cout<<"YES\n";
        return 0;
    }
    if(w >= v) {
        cout<<"NO\n";
        return 0;
    }
    int vel = v - w;
    int dist = abs(a-b);
    
    int tm = (dist-1)/vel + 1;
    
    if(tm > t) {
        cout<<"NO\n";
    }
    else cout<<"YES\n";
    return 0;
    
}