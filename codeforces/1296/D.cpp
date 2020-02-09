#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
using namespace std;
int main()
{
        
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n , a , b , k;
    
    cin>>n>>a>>b>>k;
    vector<ll>vec;
    ll pt = 0;
    
    
    for(int i =0 ; i < n ; i++) {
        
        ll tmp;
        cin>>tmp;
        
        ll val = tmp;
        
        
        tmp %= (a+b);
        if(tmp && tmp <= a ) pt++;
        else if(tmp) vec.push_back(  (tmp-a-1) / a + 1);
        else vec.push_back(  (b-1) / a  + 1);
    }
    
    sort(vec.begin() , vec.end());
    
//    for(auto x: vec) cout<<x<<" ";
//    cout<<'\n';
    
    for(auto x : vec) {
        
        if(x > k) break;
        k -=x;
        pt++;
    }
    cout<<pt<<'\n';
    return 0;
}