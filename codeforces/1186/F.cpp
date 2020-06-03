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
int n , m ;
int ara[MAX] ,deg[MAX];
vector<pii>str;
vector<pii>ans;

int main()
{
    fastRead;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    cin>>n>>m;
    for(int i =0 ; i < m ; i++ ) {
        int u , v;
        cin>>u>>v;
        str.push_back({u,v});
        deg[u]++;
        deg[v]++;
    }
    shuffle(str.begin() , str.end() , rng);
    
    
    for(int i =1 ; i <= n ; i++ ) ara[i] = deg[i];
    
    int tgt = (n+m+1)/2;
    
    for(auto x: str ) {
        
        int u = x.uu;
        int v = x.vv;
        
        if( deg[u]-1 < (ara[u] + 1 )/2 ) {
            ans.push_back(x);
            continue;
        }
        if( deg[v]-1 < (ara[v] + 1 )/2 ) {
            ans.push_back(x);
            continue;
        }
        
        deg[u]--;
        deg[v]--;
    }
    
    
    cout<<ans.size()<<'\n';
    for(auto x: ans)  {
        cout<<x.uu<<" "<<x.vv<<'\n';
    }
    return 0;
}