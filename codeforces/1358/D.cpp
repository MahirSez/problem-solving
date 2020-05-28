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

ll get(ll a , ll  cnt) {
    
    ll sum1 = (a)*(a+1)/2;
    ll aa = (a-cnt);
    ll sum2 = (aa)*(aa+1)/2;
    return sum1 - sum2;
}
/*
1 6
6
*/
int main()
{
    fastRead;
    ll n , x;
    cin>>n>>x;
    vector<ll>vec(2*n+1) , sum(2*n+1) , bsum(2*n+1);
    for(int i = 1 ; i <= n ; i++ ) cin>>vec[i];
    for(int i = 1 ; i <= n ; i++ ) vec[i+n] = vec[i];
    reverse(vec.begin()+1 , vec.end());

    
    for(int i = 1;  i<= 2*n ; i++ ) {
        
        sum[i] = vec[i] + sum[i-1];
        bsum[i] = vec[i]*(vec[i]+1)/2 + bsum[i-1];
    }
    ll ans = 0;
    ll prev =0;
    
//    for(int i =1 ; i <= 2*n ; i++ ) cout<<vec[i]<<' ';
//    cout<<'\n';
//    for(int i =1 ; i <= 2*n ; i++ ) cout<<sum[i]<<' ';
//    cout<<'\n';
//    for(int i =1 ; i <= 2*n ; i++ ) cout<<bsum[i]<<' ';
//    cout<<'\n'<<'\n';
    
    for(int i = 1 ; i <= n ; i++) {
        
        int id = upper_bound(sum.begin()+1 , sum.end() , prev + x ) - sum.begin();
        
//        cout<<i<<" "<<id<<'\n';
        
        ll tmp = sum[id-1] - sum[i-1];
        
        ll baki = x - tmp;        
        ll tmpans = bsum[id-1] - bsum[i-1];
        
        tmpans += get(vec[id] , baki);
        ans = max(tmpans , ans);
        
        prev = sum[i];
        
    }
    cout<<ans<<'\n';
    return 0;
    
}