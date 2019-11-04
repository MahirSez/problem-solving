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
    int q;
    cin>>q;
    while(q--) {
        
        ll a , b , n , s;
        cin>>a>>b>>n>>s;
        
        ll tmp = s/n;
        
        tmp = min(a , tmp);
        
        s -= tmp*n;
        
        if(s ==0 || s <= b) {
            cout<<"YES\n";
        }
        else cout<<"No\n";
    }
    return 0;
    
}