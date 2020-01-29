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
ll ans[MAX];

ll nod(ll x , ll frm , ll to) {
    
    return ( (to/x) - (frm-1)/x );
}


int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t-- ){
            
        memset(ans , 0 , sizeof ans);
        
        ll a , m , gcd;
        cin>>a>>m;
        
        gcd = __gcd(a , m);
        
        
        vector<ll>v;
        
        for(ll i = 1 ; i <= 1e5 ; i++ ) {
            
            if(m%i == 0 ) {
                v.push_back(i);
                v.push_back(m/i) ;
            }
        }
        sort(v.begin() , v.end());
        
        v.erase(unique(v.begin() , v.end()) , v.end());
        
        for(int i = v.size() -1 ; i >=0 ; i--) {
            
            ans[i] = nod(v[i] , a , a + m-1);
            
            for(int j = v.size()-1 ; j> i ; j--) {
                
                if(v[j]%v[i] == 0 ) ans[i] -= ans[j];
            }
        }
        int id = -1;
        for(int i =0 ; i < v.size() ; i++ ) {
            
            if(v[i] == gcd) id = i;
        }
        assert(id != -1);
        cout<<ans[id]<<'\n';
        
        
    }
    return 0;
}