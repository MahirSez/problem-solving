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
vector<pll>vec;
ll x0 , y00 , ax , ay , bx , by ;
ll x , y , t;

void pre() {


    vec.push_back({x0 , y00});
    
    while(1) {
        
        ll xt = vec.back().uu;
        ll yt = vec.back().vv;
        
        ll xx = ax * xt + bx;
        ll yy = ay * yt + by;
        
        
        
        
        vec.push_back({xx , yy});
        if(xx > 1e16 || yy > 1e16) return;
    }
}





int main()
{
    fastRead;
    cin>>x0>>y00>>ax>>ay>>bx>>by;
    cin>>x>>y>>t;
    
    pre();
    
    int ret = 0;
    for(int i =0 ; i < vec.size() ; i++ ) {
        for(int j =i ; j < vec.size() ; j++ ) {
            
            
            
            ll tmp1 = abs(x - vec[i].uu) + abs(y - vec[i].vv) ;
            ll tmp2 = abs(x - vec[j].uu) + abs(y - vec[j].vv) ;
            ll tmp = (vec[j].uu - vec[i].uu) + (vec[j].vv - vec[i].vv);
            
            tmp += min(tmp1 , tmp2);
            if (tmp <= t) {
                ret = max(ret , j - i + 1);
            }
        }
    }
    
    
    cout<<ret<<'\n';
    return 0;
}