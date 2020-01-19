#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    
    int t;
    cin>>t;
    while(t--) {
        ll a , b;
        cin>>a>>b;
        
        ll now = 0;
        
        int cnt = 0;
        while(1) {
            now = now*10 + 9;
            if(now <= b) cnt++;
            else break;
        }
        cout<<(1LL*a*cnt)<<'\n';
    }
    return 0;
}