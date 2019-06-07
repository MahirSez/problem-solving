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
#define MOD         998244353 
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ,deg[MAX] ;
ll fact[MAX];
int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i < n ; i++ ) {
        int u , v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
    }
    fact[0] = 1;
    for(int i =1 ; i <= n ; i++ ) {
        fact[i] = (fact[i-1] *i)%MOD;
    }
    
    ll ans = n;
    for(int i =1 ; i <=n ; i++) {
        ans = (ans * fact[ deg[i] ] )%MOD;
    }
    cout<<ans<<'\n';
    return 0;
}