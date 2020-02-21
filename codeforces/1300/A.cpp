#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n;
        cin>>n;
        int sum = 0 ;
        int ans = 0;
        for(int i = 0 ; i < n ; i++  ) {
            int tmp;
            cin>>tmp;
            if(tmp == 0) {
                ans++;
                tmp = 1;
            }
            sum += tmp;
        }
        
        if(sum ==0 ) ans++;
        cout<<ans<<'\n';
    }
    return 0;
    
}