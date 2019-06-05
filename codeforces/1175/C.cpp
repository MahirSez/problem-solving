#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         2e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n  , t , k ,ara[MAX] ;

int main()
{
    fastRead;
    cin>>t;
    while( t-- ) {
        
        cin>>n>>k;
        for(int i= 0 ; i < n ;i ++ ) cin>>ara[i];
        
        int dst = INF;
        int ans =0;
        
        
        for(int i =0 ; i +k < n ; i++ ) {
            
            if( ara[i+k] - ara[i] < dst) {
                dst = ara[i+k] - ara[i];
                ans = (ara[i+k] + ara[i] )/2;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}