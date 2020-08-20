#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

set<pii>st[N];

int main()  {
    fastio;

    int n , m ;
    cin>>n>>m;
    vector< vector<int> > vec( n+2 , vector<int>(m+2) ) , vis1 , vis2;

    for(int i =1 ; i <=n ; i++ ) {
        string s;
        cin>>s;
        for(int j =1 ; j <=m ; j++ ) {
            if(s[j-1] == '#') vec[i][j] = -1;
        }
    }
    vis1 = vec;
    vis2 = vec;

    vis1[1][1] = 1;
    for(int i = 1 ; i <=n ; i++ ) {
        for(int j =1 ; j <=m ; j++ ) {
            if(vis1[i][j] == -1) continue;
            if(vis1[i-1][j] == 1) vis1[i][j] = 1;
            if(vis1[i][j-1] == 1) vis1[i][j] = 1;

            if(vis1[i][j]) st[i+j-1].insert({i,j});
        }
    }

    // for(int i =1 ; i <= n ; i++ ) {
    //     for(int j =1 ; j <=m ; j++ ) {
    //         cout<<vis1[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    // for(int i =2 ; i <=n + m-2 ; i++ ) {
    //     cout<<i<<" ->\n";
    //     for(auto x : st[i]) cout<<x.uu<<" "<<x.vv<<"\n";
    //     cout<<'\n';
    // }

    vis2[n][m] = 1;
    for(int i = n ; i >=1 ; i-- ) {
        for(int j = m ; j >= 1 ; j-- ) {
            if(vis2[i][j] == -1) continue;
            if(vis2[i+1][j] == 1) vis2[i][j] = 1;
            if(vis2[i][j+1] == 1) vis2[i][j] = 1;
        }
    }

    for(int i =1 ; i <= n ; i++ ) {
        for(int j =1 ; j <=m ; j++ ) {
            if(vis2[i][j] != 1 ) st[i+j-1].erase({i,j});
        }
    }
    int ans = 2;

    for(int i = 2 ; i <= n + m-2 ; i++ ) ans = min(ans , (int)st[i].size());
    cout<<ans<<'\n';

    
    return 0;
}   