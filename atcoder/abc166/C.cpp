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

vector<int>edg[MAX];
int main()
{
    fastRead;
    
    int n , m;
    cin>>n>>m;
    vector<int>ara(n+1);
    for(int i = 1; i <=n ; i++ ) cin>>ara[i];
    while(m--) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    int ans = 0;
    
    for(int i =1 ; i <=n ; i++ ) {
        
        int tgt = ara[i];
        bool ok = 1;
        
        for(auto x : edg[i]) {
            if(ara[x] >= tgt) ok = 0;
        }
        if(ok) ans++;
    }
    cout<<ans<<'\n';
    return  0;
    
}