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
    int n;
    cin>>n;
    vector<ll>vec(n) , rec(n);
    for(int i =0 ; i < n ; i++ ) cin>>vec[i];
    
    for(int i =0 ; i < n ; i++ ) {
        
        ll mx = vec[i];
        ll ans = vec[i];
        for(int j = i + 1 ; j < n ; j++ ) {
            mx = min(vec[j] , mx);
            ans += mx;
        }
        mx = vec[i];
        for(int j = i-1 ; j >= 0 ; j--) {
            mx = min(vec[j], mx);
            ans +=mx;
        }
        rec[i] = ans;
    }
    
    int id = 0;
    
    for(int i =1 ; i < n; i++ ) {
        if(rec[i] > rec[id]) {
            id = i;
        }
    }
//    cout<<id<<" "<<rec[id]<<'\n';
    
    for(int j = id+1 ; j < n ; j++ ) {
        vec[j] = min(vec[j-1], vec[j]);
    }
    for(int j = id-1 ; j >= 0 ; j-- ) {
        vec[j] = min(vec[j+1], vec[j]);
    }
    
    for(auto x : vec) cout<<x<<" ";
    cout<<'\n';
    return 0;
    
}