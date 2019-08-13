#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 500;
int t , n , ara[MAX];
int main()
{
    fastRead;
    cin>>t;
    while( t-- ) {
        cin>>n;
        int st = -1;
        for(int  i =0 ; i < n ; i++ ) {
            cin>>ara[i] ;
            if(ara[i] == 1) st = i;
        }
        
        bool ok1 = true , ok2 = true;
        for(int i =st , cnt = 1 ; cnt <= n ; cnt++  ) {
            
            if(cnt != ara[i]) ok1 = false;
                
            i ++;
            i%=n;
        }
        
        for(int i = st  , cnt = 1; cnt <=n ; cnt++) {
            
            if( cnt!= ara[i]) ok2 = false;
            
            i--;
            
            i +=n;
            i%=n;
        }
        
        if( ok1 || ok2 ) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}