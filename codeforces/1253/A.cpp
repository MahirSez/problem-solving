#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int a[MAX] , b[MAX];
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n;
        cin>>n;
        for(int i =0 ; i < n ; i++ ) cin>>a[i];
        for(int i =0 ; i < n ; i++ ) cin>>b[i];
        
        int l = 0, r = n-1;
        
        for(int  i=0 ; i < n ; i++ ) {
            if(a[i] != b[i]) {
                l = i;
                break;
            }
        }
        
        for(int  i=n-1 ; i>=0 ; i-- ) {
            if(a[i] != b[i]) {
                r = i;
                break;
            }
        }
        bool ok = 1;
        for(int i = l ; i <=r ; i++ ) {
            
            if(a[i] > b[i]) ok = 0;
            if(a[i ] - b[i] != a[l] - b[l]) ok = 0;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    return 0;
}