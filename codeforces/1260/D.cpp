#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

typedef tuple<int,int,int> tp;

int main()  {
    fastio;

    int m , n , k , t;
    cin>>n>>m>>k>>t;

    if(t < (m+1)) {
        cout<<0<<'\n';
        return 0;
    }
    vector<int>vec(n);
    for(int i = 0 ; i < n ; i++ ) cin>>vec[i];


    vector<tp>rec(k);
    for(int i = 0 ; i < k ; i++ ) {
        int l ,r , d;
        cin>>l>>r>>d;
        rec[i] = {l,r,d};


    }



    sort(rec.begin() , rec.end());


    int lo = 0 , hi = 1e6 , ret = -1;

    t -= (m+1);

    // cout<<t<<'\n';

    while(lo <= hi ) {
        int mid = (lo+hi)/2;
        int tot = 0;


        int last = 0;

        for(auto x : rec) {
            int l ,r , d;
            tie(l , r , d ) = x;
            if(d <= mid) continue;

            tot += max( 0 , 2* (r - max(last , l-1) ) );
            last = max(last , r);
        }

        // cout<<mid<<" "<<tot<<'\n';


        if(tot <= t) {
            ret = mid;
            hi = mid - 1;
        }
        else {
            lo = mid +1;
        }
    }

    // cout<<ret<<'\n';

    int ans =0;
    for(auto x : vec) {
        if(x >= ret) ans++;
    }
    cout<<ans<<'\n';
    return 0;

    
}