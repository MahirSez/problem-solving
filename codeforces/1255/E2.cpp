#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
 
const int MAX = 1e6 + 6;
ll n , ara[MAX];
 
vector<ll> prm;


 
ll get(vector<pll>&vec , ll tot) {
 
    
    ll mid = (tot-1)/2 +1 , cnt = 0;
    
    int id = -1;
    

    
    for(auto x: vec) {
        
        cnt += x.uu;
        if(cnt >= mid) {
            id = x.vv;
            break;
        }
    }
    
    ll ret = 0;
    
    for(auto x : vec) {
        
        ret += abs(x.vv - id)*x.uu;
    }
    
//    cout<<tot<<" -> "<<id<<" = "<<ret<<'\n';
//
//    for(auto x : vec) cout<<x.uu<<" ";
//    cout<<'\n';
//    
    
    return ret;
    
    
}
 
 
 
ll solve(ll div) {
 
    ll ret = 0;
    ll cnt = 0;
    vector<pll> vec;

    
    for(int i =1; i <=n ; i++ ) {
        
        if(cnt + ara[i] < div) {
            vec.push_back({ara[i] , i});
            cnt += ara[i];
            continue;
        }
        
        
        ll extra = div - cnt;
        vec.push_back({ extra , i});
        ret += get(vec , div);
        
        ll rem = ara[i] - extra;
        rem %= div;
        
        vec.clear();
        cnt = rem;
        vec.push_back({rem , i});
        
    }
    
    assert(cnt == 0);
    
    
    return ret;
}
 
int main()
{
    fastRead;
    cin>>n;
    ll num = 0;
    for(int i =1 ; i<=n ; i++ ) {
        cin>>ara[i];
        num += ara[i];
    }
    
    if(num == 1) {
        cout<<-1<<'\n';
        return 0;
    }
    
    
    for(ll i =2 ; i*i <=num ; i++ ) {
        
        if(num%i ) continue;
            
        prm.push_back(i);
        
        while(num%i==0 ) num/=i;
    }
    
    if(num > 1) prm.push_back(num);
    
    ll ans = INF;
    for(auto x : prm) {
        
        ans = min(ans , solve(x) );
    }
    cout<<ans<<'\n';
    return 0;
    
    
}