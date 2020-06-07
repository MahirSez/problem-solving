#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e12
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
const ll MOD = 1e9 + 7;


ll get(ll n, ll powDiff, ll base, ll mul) {
    
    if(mul > INF) return -1;
    
    ll ret = mul;
    for(int i =0 ; i < powDiff ; i++ ) {
        
        if(ret * base > INF ) return -1;
        ret *=base;
    }
    return ret;
}

ll bigmod(ll a, ll b) {
    
    if( b == 0) return 1LL;
    ll ret = bigmod(a, b/2);
    ret  = (ret * ret) % MOD;
    if( b & 1) ret = (ret * a)%MOD;
    return ret;
}

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n, p;        
        cin>>n>>p;
        vector<int>vec(n);
        for(int i =0 ; i < n ; i++ ) {
            cin>>vec[i];
        }
        
        if(p ==1 ) {
            cout<<n%2<<'\n';
            continue;
        }
        
        sort(vec.rbegin(), vec.rend());
        
        vector<pii>rec;
        
        
        int last = vec[0];
        int cnt = 1;
        for(int i = 1 ; i < n ; i++ ) {
            
            if(last != vec[i]) {
                rec.push_back({last, cnt});
                last = vec[i];
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        rec.push_back({last, cnt});
        int msb = -1;
        
//        for(int i =0 ; i < rec.size(); i++ ) cout<<rec[i].uu<<" "<<rec[i].vv<<'\n';
        
        for(int i =0 ; i < rec.size(); i++ ) {  
            
            if( rec[i].vv%2 == 0 ) continue;
            
            ll lagbe = 1;
            for(int j = i+1 ; j < rec.size() ; j++ ) {
                
                lagbe = get(n, rec[j-1].uu - rec[j].uu, p , lagbe);
                
                if(lagbe  == -1) {
                    break;
                }
                
                if(lagbe <= rec[j].vv ) {
                    i = j-1;
                    rec[j].vv -= lagbe;
                    lagbe = 0;
                    break;
                }
                else {
                    lagbe -= rec[j].vv;
                }
            }
            if( lagbe ==0) continue;
            msb = i;
            break;
        }
        
        if(msb == -1) {
            cout<<0<<'\n';
            continue;
        }
//        cout<<msb<<" "<<rec[msb].uu<<" "<<rec[msb].vv<<'\n';
        ll ans = bigmod(p, rec[msb].uu)  ;
        
//        cout<<ans<<'\n';
        
        for(int i = msb + 1 ; i < rec.size() ; i++ ) {
            
            ans -= ( bigmod(p, rec[i].uu) * rec[i].vv)%MOD;
            ans %=MOD;
            if( ans < 0) ans += MOD;
        }
        cout<<ans<<'\n';
    }
    return 0;
}