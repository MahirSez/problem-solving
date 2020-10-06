#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 220;
int n , l , k;
double dp[N][N][N*2], p[N];
int vis[N][N][N*2];
int cap[N];

double solve(int id , int taken , int c) {
    if(id == n ) return c >= 200 && taken >= l;

    if(vis[id][taken][c]) return dp[id][taken][c];
    vis[id][taken][c] = 1;

    return dp[id][taken][c] = p[id]*solve(id+1 , taken +1 , min(400 , c + cap[id] ) ) + (1.0 - p[id]) * solve(id+1 , taken , c);
}


int main()  {
    fastio;

    cin>>n>>l>>k;
    for(int i =0 ; i < n ; i++ ) cin>>p[i] , p[i]/=100.0;

    for(int i =0 ; i < n ; i++ ) cin>>cap[i];
    
    cout<<setprecision(10)<<fixed<<solve(0 , 0 , 200 + k )<<'\n';
    return 0;
    
    
    
}