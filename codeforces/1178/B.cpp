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
vector<ll>vec;
string str;
int main()
{
    fastRead;
    cin>>str;
    ll cnt1 = 0 , cnt2 = 0;
    ll ans = 0;
    
    string  nw = "";
    
    for(auto x : str) {
        if( x == 'v') {
                
            while( cnt2  >  0 )  {
                nw += 'o';
                cnt2--;
            }
            cnt2 = 0;
            cnt1++;
        }
        
        else {
            
            while( cnt1 > 1) {
                
                nw += 'v';
                cnt1--;
            }
            cnt1 = 0;
            cnt2++;
        }
    }
    
    while( cnt1 > 1) nw += 'v' , cnt1--;
    while( cnt2 > 0) nw += 'o' , cnt2--;
    
    cnt1 = 0 ;
    cnt2 = 0;
    
    for(auto x : nw) {
        if( x == 'v') cnt1++;
    }
    
    for(auto x : nw) {
        
        if( x == 'o') {
            ans += cnt1*cnt2;
        }
        else {
            cnt1--;
            cnt2++;
        }
    }
    cout<<ans<<'\n';
    
}