#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

int n ;
vector<int>edg[MAX];


double dfs(int node , int par) {

    
    double ret = 0;
    int cnt= 0;
    
    for(auto x : edg[node]) {
        if(x == par) continue;
        ret += dfs(x , node);
        cnt++;
    }
    if(cnt > 0 )ret /= cnt;
    ret++;
    return ret;
}


int main()
{
    fastRead;
    cin>>n;
    
    for(int i =1; i <n ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    double ans = dfs(1 , -1)-1;
    cout<<setprecision(10)<<fixed<<ans<<'\n';
    return  0;
    
    
}