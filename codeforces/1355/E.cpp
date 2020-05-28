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

ll  n ,a , r , m;
vector<ll>vec , rise , fall;
ll ans = 1e18;

void solve(ll tgt) {
    
    int id = upper_bound(vec.begin() , vec.end() , tgt) - vec.begin();
    ll riseCnt  = 0, fallCnt = 0;
    riseCnt = rise[id-1] + (tgt - vec[id-1])*id;
    if(id < n ) fallCnt = vec[id] - tgt;
    if(id +1 < n ) fallCnt += fall[id+1] + (vec[id+1] - tgt)*(n - id - 1);
    
//    cout<<" "<<tgt<<" "<<riseCnt<<" "<<fallCnt<<'\n';
    
    ll mn = min(riseCnt , fallCnt);
    
    riseCnt -= mn;
    fallCnt -= mn;
    
    ll tmp = mn*m + riseCnt * a + fallCnt * r;
    
    ans = min(ans , tmp);
    
}

int main()
{
    fastRead;
    cin>>n>>a>>r>>m;
    m = min(m , a + r);
    vec.resize(n );
    rise.resize(n);
    fall.resize(n);
    
    
    ll sum = 0;
    for(int i =0 ; i < n ; i++ ) cin>>vec[i] , sum += vec[i];
    
    sort(vec.begin() , vec.end());
    
    for(int i = 1; i < n ; i++ ) {
        
        ll diff = vec[i] - vec[i-1];
        rise[i] = rise[i-1] + diff * i;
    }
    
    
    for(int i = n-2 ; i >=0 ; i--) {
        ll diff = vec[i+1] - vec[i];
        fall[i] = fall[i+1] + diff * (n - i - 1);
    }
    
//    for(int i =0 ; i < n ; i++) cout<<vec[i]<<" "<<rise[i]<<" "<<fall[i]<<'\n';
    solve(sum/n);
    solve(sum/n + 1);
    
    for(auto x : vec) solve(x);
    
    cout<<ans<<'\n';
    
}