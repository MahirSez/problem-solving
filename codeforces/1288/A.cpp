#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n , d;
        cin>>n>>d;
        
        int x = sqrt(d-1) - 1;
        bool ok = 0;
        
        for(int i = max(x-100, 0) ; i <= min(x + 100 , d) ; i++ ) {

            if(i + (d-1)/(i+1) + 1 <= n ) {
                ok = 1;
            }
        }
        if(ok ) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}