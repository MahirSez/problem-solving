#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
const int MAX =4e5 + 5;
 
int  n , I , ara[MAX];
 
map<int,int>mp;
 
 
 
ll get() {
 
    
    ll musk = 1;
    int power = 0;
    
    while(1) {
        
        if(  power < 40 && (power +1)  *n <= 8LL * I ) {
            
            musk *=2LL;
            power++;
        }
        else break;
    }
    
    
    
    return musk;
 
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    
    cin>>n>>I;
//    cout<<get()<<endl;
    
    for(int i = 0 ; i < n ; i++ ) {
        int tmp;
        cin>>tmp;
        mp[tmp]++;
    }
    
    int id = 0;
    
    for(auto x : mp) {
        
        ara[++id] = x.second;
    }
    
    ll k = get();
    
    if(id <= k) {
        cout<<0<<endl;
        return 0;
    }
    
    
    for(int i =1 ; i <=id ; i++ ) {
        
        ara[i] +=ara[i-1];
    }
    
    int mx = 1e9;
    for(int i = 1 , j = k ; j<=id ; j++ , i++ ) {
        
        int tmp = ara[j] - ara[i-1];
        
        tmp = n - tmp;
        
        mx = min(mx , tmp);
    }
    cout<<mx<<'\n';
    return 0;
}