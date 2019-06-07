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
#define MAX         500005
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m , mxR[MAX] , table[MAX][20];
int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < n ; i++ ) {
        int l , r;
        cin>>l>>r;
        mxR[l] = max(mxR[l] , r);
    }
    memset(table , -1 , sizeof table);
    
    for(int i = 1 ; i < MAX ; i++ ) {
        mxR[i] = max(mxR[i] , mxR[i-1]);
    }
    for(int i =0 ; i < MAX ; i++ ) {
        if( mxR[i] >i ) table[i][0] = mxR[i];
    }
    
    for(int i =1 ; i<20 ; i++ ) {
        
        for(int j = 0 ; j < MAX ;j++ ) {
            
            if(table[j][i-1] == -1) continue;
            table[j][i] = table[ table[j][i-1] ][i-1];
        }
    }
    
    while( m-- ) {
        
        int l , r;
        cin>>l>>r;
        
        int ans = 0;
        
        for(int i = 19 ; i>=0 ; i-- ) {
            
            if( table[l][i] == -1) continue;
            
            if(table[l][i] < r ) {
                ans += (1<<i);
                l = table[l][i];
            }
        }
        if(table[l][0] >= r) cout<<ans+1<<'\n';
        else cout<<"-1\n";
    }
    
    return 0;
}