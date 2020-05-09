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
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        ll n , k;
        cin>>n>>k;
        ll lo = 1 , hi = 1e15 , ret = -1;
        while(lo <= hi) {
            
            ll mid = (lo+hi)/2;
            if(mid%n ==0 ) mid++;
            
            ll cnt = (mid/n)*(n-1) + mid%n;
            
            if(cnt == k) {
                ret = mid;
                break;
            }
            else if(cnt > k) hi = mid-1;
            else lo = mid+1;
        }
        assert(ret != -1);
        cout<<ret<<'\n';
        
    }
    return 0;
}