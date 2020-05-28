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


int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n , k;
        cin>>n>>k;
        vector<int>vec(n) ;
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        bool ok = 0;
        for(auto x : vec) {
            if(x == k) ok = 1;
        }
        if(!ok) {
            cout<<"no\n";
            continue;
        }
        ok = 0;
        if( n== 1) ok = 1;
        
        int last = -1;
        
        for(int i =0 ; i < n  ; i++ ) {
            
            if(vec[i]>=k ) {
                
                if(last >= 0 && i - last <=2) ok = 1;
                last = i;
            }
        }
        
        if(ok) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}