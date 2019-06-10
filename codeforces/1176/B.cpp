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
int t , n , ara[200] , rec[3];
int main()
{
    fastRead;
    cin>>t;
    while( t-- ) {
        memset(rec , 0 , sizeof rec);
        cin>>n;
        for(int i =0 ; i < n ; i++ ) {
            int tmp;
            cin>>tmp;
            rec[tmp%3]++;
        }
        
        int ans = rec[0];
        
        int tmp = min(rec[1] , rec[2]);
        ans += tmp;
        rec[1] -= tmp;
        rec[2] -= tmp;
        
        ans += rec[1]/3 + rec[2]/3;
        cout<<ans<<'\n';
    }
    return 0;
}