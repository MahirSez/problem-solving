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
        int n ;
        cin>>n;
        vector<int>vec(n+1) , ans(n+1);
        for(int i =1 ; i <= n ; i++ ) cin>>vec[i];
        for(int i =1 ; i <= n ; i++ ) ans[i] = 1;
        
        for(int i = 1 ; i <=n ; i++ ) {
            
            for(int j = 2*i  ; j <= n ; j+=i) {
                
                if(vec[j] > vec[i]) ans[j]= max(ans[j] , ans[i] + 1);
            }
        }
        
        int ret = 0;
        for(auto x : ans) ret = max(ret , x);
        cout<<ret<<'\n';
    }
    return 0;
    
}