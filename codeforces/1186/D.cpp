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
int n  ;
double ara[MAX] ;
int main()
{
    fastRead;
    cin>>n;
    vector<double>pos , neg;
    
    ll sum = 0;
    for(int i =0 ; i < n ; i++ ) {
        
        cin>>ara[i];
        int tt = ara[i];
        sum += tt ;
    }
    
    
    for(int i =0 ; i < n ; i++ ) {
        
        if(sum < 0 ) {
            int tmp = ceil(ara[i]);
            sum += tmp - int(ara[i]);
            cout<<tmp<<'\n';
        }
        else if( sum > 0 ){
            int tmp = floor(ara[i]);
            sum +=  tmp - int(ara[i]) ;
            cout<<tmp<<'\n';
        }
        else cout<<int(ara[i])<<'\n';
    }
    
    
    
    assert(sum ==0 );
    return 0;
}
