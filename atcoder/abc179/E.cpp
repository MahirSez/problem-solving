#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 998244353;

const int N = 1e6 + 6;

int main()  {
    fastio;
    ll n , x , m;
    cin>>n>>x>>m;
    vector<ll>vals , rec(m, -1), cyc;

    for(int i =0 ; rec[x] == -1; i++) {
        vals.push_back(x);
        rec[x] = i;
        x = (x*x)%m;
    }


    int id = rec[x];

    // for(auto x : vals) cout<<x<<" ";
    // cout<<'\n';

    if(n < id) {
        ll tot = 0;
        for(int i =0 ; i < n ; i++ ) tot += vals[i];
        cout<<tot<<'\n';
        return 0;
    }

    ll tot1 = 0 , tot2 = 0;
    for(int i =0 ; i < id ; i++ ) tot1 += vals[i] ;
    



    for(int i =id ; i < vals.size() ; i++ ) cyc.push_back(vals[i]);
    for(auto x : cyc) tot2 += x ;

    // cout<<tot1<<" "<<tot2<<'\n';

    n -= id;

    // cout<<n<<" "<<id<<'\n';

    ll times = n / cyc.size();
    int rem = n % cyc.size();

    ll ans = tot1;

    ans += times * tot2 ;

    for(int i =0 ; i < rem ; i++ ) ans += cyc[i];
    cout<<ans<<'\n';
    return 0;





}