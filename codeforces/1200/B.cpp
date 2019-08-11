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
int ara[200];
int t , n , m , k;


int main()
{
    fastRead;
    cin>>t;
    while( t-- ) {
        memset(ara , 0 , sizeof ara);
        cin>>n>>m>>k;
        
        for(int i =0 ; i < n ; i++ ) cin>>ara[i];
        
        bool ok = true;
        
        for(int i =0 ; i < n-1 ; i++ ) {
            
                
            if( ara[i] >= ara[i+1] ) {
                
                int tgt = max(0 , ara[i+1] - k );
                m +=  ara[i] - tgt ;
                ara[i] = tgt;
            }
            else {
                
                int tgt = max(ara[i+1] - k , 0 );
                
                m -=  tgt - ara[i];
                if( m < 0 ) {
                    ok = false;
                    break;
                }
                
                ara[i] = tgt;
            }
            
        }
        
        if( ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}