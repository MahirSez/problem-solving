#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e5 + 5;
int main()
{
    fastRead;
    
    int t;
    cin>>t;
    while(t--) {
        
        int n;
        cin>>n;
        if(n&1) {
            if(n == 1) cout<<"FastestFinger\n";
            else cout<<"Ashishgup\n";
            continue;
        }
        int cnt = 0;
        while(n%2 == 0 ) {
            n/=2;
            cnt++;
        }
        
        if(n ==1) {
                
            if(cnt == 1) cout<<"Ashishgup\n";
            else cout<<"FastestFinger\n";
            continue;
        }
        if(cnt > 1) {
            cout<<"Ashishgup\n";
            continue;
        }
        
        int p = 0;
        for(int i = 3 ;i < MAX; i++ ) {
            if(n%i) continue;
            while(n%i == 0 ) p++, n/=i;
        }
        if(n != 1) p++;
        if( p == 1) cout<<"FastestFinger\n";
        else cout<<"Ashishgup\n";
        
    }
    return 0;
}