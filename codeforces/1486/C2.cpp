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
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int cnt = 0;

int ask(int l , int r) {
    cnt++;
    assert( cnt <= 20);
    // cout<<l<<" "<<r<<endl;
    assert(l < r);

    cout<<"? "<<l<<" "<<r<<endl;
    
    int ret;
    cin>>ret;
    return ret;
}

int main()  {
    // fastio;
    int n;
    cin>>n;
    int sbest = ask(1, n);
    int side ;
    if(sbest == 1) side = 1;
    else if(sbest == n) side = 0;
    else if( ask(1,sbest) == sbest) side = 0;
    else side = 1;

    if(n ==2) {
        cout<<"! "<<((sbest == 1) ? 2 : 1)<<endl;
        return 0;
    }

    int lo, hi;
    if(side == 0) lo = 1, hi = sbest-1;
    else lo = sbest+1, hi = n;

    int ans = -1;

    // cout<<side<<endl;

    while(lo<=hi) {

        int mid = (lo+hi)/2;

        // cout<<"---"<<lo<<" "<<hi<<" "<<mid<<endl;

        int ret = (side == 0)?  ask(mid, sbest) : ask(sbest , mid);

        if(ret == sbest) {
            ans = mid;

            if(side == 0) lo = mid+1;
            else hi = mid - 1;
        }
        else {
            if(side== 0) hi = mid - 1;
            else lo = mid + 1;
        }
        
    }
    assert(ans != -1);
    cout<<"! "<<ans<<endl;

    return 0;
}