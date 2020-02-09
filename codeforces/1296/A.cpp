#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        
        int sum = 0;
        int n;
        cin>>n;
        bool odd = 0 , ev = 0;
        while(n--) {
            int tmp;
            cin>>tmp;
            if(tmp&1) odd = 1;
            else ev = 1;
            sum += tmp;
        }
        if(sum&1) cout<<"YES\n";
        else if(odd && ev) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    return 0;
}