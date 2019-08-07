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
int t ;
ll n;



vector<ll>vec , pre;


void solve(ll tgt) {

    
    while(tgt != 0 ) {
        
        
        
        int id = upper_bound(pre.begin()  , pre.end() , tgt) - pre.begin();
        
        id--;
        
        vec.push_back(id);
        
        tgt -= pre[id];
    }
    
//    for(auto x: vec) cout<<x<<" ";
//    cout<<endl;
}



int main()
{
    fastRead;
    
    cin>>t;
    
    
    
    for(ll i = 0 ; i< MAX ; i++ ) {
        
        pre.push_back(  (1LL * i * (i-1)/2) ) ;
    }
    
    
    while( t-- ) {
        
        cin>>n;
        
        vec.clear();
        solve(n);
        
        reverse(vec.begin() , vec.end() ) ;
        
        
        string ans = "";
        ans += '7';
        
        
        int three = 0;
        
        for(auto x : vec ) {
            
            while(three < x) {
                ans += '3';
                three++;
            }
            ans += '1';
        }
        
        reverse(ans.begin() , ans.end()) ;
        cout<<ans<<'\n';
        
    }
    return 0;
}