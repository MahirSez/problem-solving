#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int const MAX = 1e6 + 6;
ll sum  ;
int main()
{
    int n;
    cin>>n;
    
    vector<int>v;
    
    ll sum = 0;
    
    for(int i =0 ; i < n ; i++ ) {
        
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
        sum += tmp;
    }

    
    sort(v.begin() , v.end() ) ;
    
    ll tmp = v[n-1];
    
    if( sum %2 ==0 && tmp *2 <= sum ) {
        
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;  
    
    

    
    return 0;
}