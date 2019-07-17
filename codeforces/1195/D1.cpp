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
#define MAX         100005
#define MOD         998244353 
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
vector<ll>edg[MAX] ;
ll sum ;
int main()
{
    fastRead;
    cin>>n;

    for(int i =0 ; i < n ; i++ ) {
        
        int tmp;
        cin>>tmp;
        while( tmp ) {
            
            edg[i].push_back(tmp%10);
            tmp/=10;
        }
    }
    
    int sz = edg[0].size();
    
    ll ten = 1;
    
    for(int i =0 ; i < sz ; i++ ) {
        
        
        ll tot = 0;
        for(int j =0 ; j < n ; j++ ) {
            tot += edg[j][i];
        }
        
        tot = (tot*n)%MOD;
        
        sum =  ( sum + (tot*ten) %MOD )%MOD;
        
        ten *=10;
        ten %=MOD;
        sum =  ( sum + (tot*ten) %MOD )%MOD;
        
        ten *=10;
        ten %=MOD;
        
    }
    
    cout<<sum<<endl;
    return 0;
}
