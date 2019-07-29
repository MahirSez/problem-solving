#include<bits/stdc++.h>
#define MAX 300005
#define ll long long int
using namespace std;
 
int n;
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin>>n;
 
    
    ll baki = 0 , ans = 0;
    for(int i = 0 ; i < n ; i++ ) {
        ll num;
        cin>>num;
        
        ll tmp = min(baki , num/2);
        
        ans += tmp;
        
        baki -= tmp;
        num -= 2*tmp;
        
        ans += num/3;
        baki += num%3;
    }
    
    cout<<ans<<endl;

    return 0;
}
    
    