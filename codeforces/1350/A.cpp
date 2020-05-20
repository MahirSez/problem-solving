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
        for(int i = 2 ; i <=n ; i++) {
            if(n%i == 0) {
                n += i;
                break;
            }
        }
        
        if(k ==1 ) {
            cout<<n<<'\n';
            continue;
        }
//        cout<<n<<'\n';
        
        cout<<1LL*(n + (k-1)*2)<<'\n';
        
    }
    return 0;
    
}