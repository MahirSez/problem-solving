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
        
        int n , k;
        cin>>n>>k;
        if( n-k+1 >0 && (n-k+1 )%2 ) {
            
            
            cout<<"YES\n";
            for(int i =0 ; i < k -1 ; i++ ) cout<<1<<" ";
            cout<<n-k+1<<'\n';
        }
        
        else if( n -2*k + 2 > 0 && (n- 2*k + 2) %2 ==0 ) {
            cout<<"YES\n";
            for(int i =0 ; i < k -1 ; i++ ) cout<<2<<" ";
            cout<<n-2*k+2<<'\n';
        }
        else cout<<"NO\n";
    }
    return 0;
    
}