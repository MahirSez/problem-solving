#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e18
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int n , m , x[MAX] , s[MAX];

ll dp[MAX];

ll solve(int now) {
    
    if(now > m ) return 0;
    ll &ret = dp[now];
    if( ret != -1) return ret;
    
    ret = INF;
    
    for(int i =0 ; i < n ; i++ ) {
        
        int frm = x[i] - s[i];
        int to = x[i] + s[i];
        
        if(now >= frm && now <=to ) ret = min(ret , solve(now+1));
        if(now > to) ret = min(ret , solve(now+1)+1 );
        if(now < frm) ret = min(ret , frm - now + solve(to + frm - now + 1) ) ;
    }
    return ret;
}


int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0; i <n ; i++) {
        cin>>x[i]>>s[i];
    }
    
    memset(dp , -1 , sizeof dp);
    cout<<solve(1)<<'\n';
    
    return 0;
    
}