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

const int N = 1e6 + 6;

int ara[200][200];

int main()  {
    fastio;
    int n , m;
    cin>>n>>m;
    for(int i = 1; i <=n ; i++ ) {
        string s ;
        cin>>s;
        for(int j = 0 ; j < m ; j++ ) {
            if(s[j] == '#') ara[i][j+1] = -1;
        }
    }
    int ans = 0;

    for(int i =1 ; i <=n ; i++ ) {
        for(int j =1 ; j <= m ; j++ ) {
            if(j < m && ara[i][j] == 0 && ara[i][j+1] ==0 ) ans++;
            if(i < n && ara[i][j] == 0 && ara[i+1][j] ==0 ) ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
    
    
}