#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int t , n ; 
int main()
{
    fastRead;
    cin>>t;
    while(t-- ) {
        
        
        int n  ;
        cin>>n;
        vector<int>vec;
        for(int i = 0 ; i < n ; i++ ) {
            int tmp;
            cin>>tmp;
            vec.push_back(tmp);
        }
        sort(vec.rbegin() , vec.rend()) ;
        
        int k = min(vec[0] , vec[1]) -1;
        
        k = min( k , n-2 ) ;
        cout<<k<<'\n';
    }
    return 0;
}