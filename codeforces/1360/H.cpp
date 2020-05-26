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


bool ok(ll mid , vector<ll>&vec , ll till) {

    int n = vec.size();
    ll lo = mid , hi = till - mid;
    
    for(auto x : vec) {
        if(x == mid) return 0;
        
        if(x < mid) lo--;
        else hi--;
    }
    
//    cout<<mid<<" -- "<<lo<<" "<<hi<<'\n';
    if(lo == hi) return 1;
    if(lo + 1 == hi) return 1;
    return 0;
}

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n , m;
        cin>>n>>m;
        vector<ll>vec(n);
        for(int i =0 ; i < n ; i++ ) {
            string str;
            cin>>str;
            ll tmp = 0;
            for(auto x : str) {
                tmp = tmp*2 + (x-'0');
            }
            vec[i] = tmp;
        }
        sort(vec.begin() , vec.end());
//        for(auto x : vec) cout<<x<<'\n';
//        cout<<'\n';
//        
        ll till = (1LL<<m)-1;
        ll mid = till/2;
        
        ll frm = max(0LL , mid-200);
        ll to = min(till , mid+200);
        bool okk = 0;
        
        for(ll i = frm ; i <= to ; i++ ) {
            
            if(!ok(i , vec , till)) continue;
            
            string ret = "";
            for(int j =0 ; j < m ; j++ ) {
                ret += char(i%2 + '0');
                i/=2;
            }
            reverse(ret.begin() , ret.end());
            cout<<ret<<'\n';
            okk = 1;
            break;
        }
        assert(okk);
    }
    return 0;
}