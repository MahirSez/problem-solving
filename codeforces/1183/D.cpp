#include<bits/stdc++.h>
#define MAX 200005

using namespace std;
typedef long long int ll;
vector<int>vec;
map<int,int>mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    
    cin>>t;
    while( t-- ) {
    
        int n;
        cin>>n;
        vec.clear();
        mp.clear();
        
        for(int i =0 ; i < n ; i++ ) {
            int tmp;
            cin>>tmp;
            
            mp[tmp]++;
        }
        
        
        for(auto x : mp) vec.push_back(x.second);
        
        
        sort(vec.rbegin() , vec.rend() ) ;
        
        
        for(int i =1 ; i< vec.size() ; i++ ) {
            vec[i] = max(0 , min(vec[i] , vec[i-1]-1) );
        }
        int ans = 0 ;
        
        for(auto x : vec) ans += x;
        
        cout<<ans<<'\n';
    }
    return 0;
}