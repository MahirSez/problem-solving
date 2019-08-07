#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string s1 , s2;
int t;
int main()
{
    fastRead;
    cin>>t;
    while( t-- ) {
        
        cin>>s1>>s2;
        
        
        int n1 = s1.size();
        int n2 = s2.size();
        
        reverse(s1.begin() , s1.end() ) ;
        reverse(s2.begin() , s2.end() ) ;
        
        int id2 = -1;
        for(int i =0 ; i < n2 ; i++ )  {
            
            
            if( s2[i] == '1') {
                
                id2= i;
                break;
            }
        }
        
        int ans =0;
        
        for(int i = id2 ; i < n1 ; i++ ,ans++) {
            
            if( s1[i] == '1') {
                break;
            }
        }
        
        cout<<ans<<'\n';
    }
    return 0;   
}