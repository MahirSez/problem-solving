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
        
        string a , b , c;
        cin>>a>>b>>c;
        int n = a.size();
        bool ok = 1;
        for(int i =0 ; i < n ; i++ ) {
            
            if(a[i] != c[i] && b[i] != c[i]) ok = 0;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}