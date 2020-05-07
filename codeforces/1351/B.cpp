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
        
        int a , b , c , d;
        cin>>a>>b>>c>>d;
        if(a == c && b + d == a) cout<<"YES\n";
        else if(a ==d && b + c == d) cout<<"YES\n";
        else if(b ==c && a + d == b) cout<<"YES\n";
        else if(b ==d && a + c == b)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    
}