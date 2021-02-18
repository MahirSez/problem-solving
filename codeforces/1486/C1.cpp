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
    assert( cnt <= 40);
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
    int lastid = -1;

    int lo = 1, hi = n;
    while(lo +1 < hi) {

        if(lastid == -1) lastid = ask(lo, hi);
        int mid = (lo+hi)/2;

        // cout<<"---"<<lo<<" "<<hi<<" "<<mid<<endl;

        if(lastid <= mid && lo == mid)  mid++;
        else if(lastid > mid && mid + 1 == hi) mid--;

        int ret = (lastid <= mid)?  ask(lo, mid) : ask(mid+1 , hi);

        if(lastid == ret) {
            if(lastid <= mid) hi = mid;
            else lo = mid+1;
            lastid = ret; 
        }
        else {
            if(lastid <= mid) lo = mid+1;
            else hi = mid;
            lastid = -1;
            // ansl = mid+1 , ansr = hi;
        }

        // cout<<lo<<" "<<hi<<" "<<lastid<<endl;
        
    }

    if(lo == hi) {
        if(lo > 1) lo--;
        else hi++;
    }
    int ret = ask(lo, hi);

    cout<<"! "<<(ret == lo ? hi : lo)<<endl;
    
    // cout<<"! "<<(lastid == lo ? hi : lo)<<endl;
    return 0;
}