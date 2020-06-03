#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 5e5 + 5;
int n;
ll ara[MAX], lcst[MAX], rcst[MAX];
ll rec[MAX], ans[MAX];
ll llim[MAX], rlim[MAX];

void pre() {
    
    stack<pll>st1;
    for(int i = 1 ; i <= n ; i++ ) {
        
        ll totcnt = 1;
        while(!st1.empty() && ara[i] <= ara[st1.top().uu]) {
            totcnt += st1.top().vv;
            st1.pop();
        }
        lcst[i] = totcnt * ara[i] + ( st1.empty() ? 0 : lcst[st1.top().uu] );
        llim[i] = st1.empty() ? 1 : st1.top().uu + 1;
        st1.push({i, totcnt});
    }
    
    while(!st1.empty()) st1.pop(); 
    
    for(int i = n ; i >= 1 ; i-- ) {
        
        ll totcnt = 1;
        while(!st1.empty() && ara[i] <= ara[st1.top().uu]) {
            totcnt += st1.top().vv;
            st1.pop();
        }
        rcst[i] = totcnt * ara[i] + ( st1.empty() ? 0 : rcst[st1.top().uu] );
        rlim[i] = st1.empty() ? n : st1.top().uu - 1;
        st1.push({i, totcnt});
    }
}


int main()
{
    fastRead;
    cin>>n;
    for(int i =1  ; i <= n ; i++) cin>>ara[i];
    pre();
    
    for(int i =1 ; i <= n ; i++ ) {
        rec[i] = (rlim[i] - llim[i] + 1) * ara[i] + lcst[llim[i]-1] + rcst[rlim[i]+1];
    }
//    
//    for(int i =1 ; i <=n ; i++ ) {
//        cout<<i<<" --> "<<llim[i]<<" "<<rlim[i]<<'\n';
//    }
//    
    int id = 1;
    for(int i =1 ; i <=n ; i++ ) {
        if(rec[i] > rec[id]) id = i;
    }
    
    
    ans[id] = ara[id];
    for(int i = id+1 ; i <=n ; i++ ) ans[i] = min(ans[i-1], ara[i]);
    for(int i = id-1 ; i >=1 ; i-- ) ans[i] = min(ans[i+1], ara[i]);
    for(int i =1 ; i <=n ; i++ ) cout<<ans[i]<<" ";
    cout<<'\n';
    
    return 0; 
}