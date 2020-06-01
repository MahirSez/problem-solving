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
ll ro[100][2] , col[100][2];
ll pw[100];

void pre() {
    pw[0] = 1;
    for(int i =1 ; i <= 50; i++ ) pw[i] = (pw[i-1]*2LL);
}
int main()
{
    fastRead;
    pre();
    int n, m;
    cin>>n>>m;
    for(int i =1 ; i <=n ; i++ ) {
        for(int j =1 ; j <=m ;j++ ) {
            int tmp;
            cin>>tmp;
            ro[i][tmp]++;
            col[j][tmp]++;
        }
    }
    
    ll ans = 0;
    

    
    for(int i =1 ; i <=n ; i++ ) {
        ans += pw[ro[i][0]] + pw[ro[i][1]] -2;
    }
    for(int i =1 ; i <=m ; i++ ) {
        ans += pw[col[i][0]] + pw[col[i][1]] -2;
    }    
    ans -= (n*m);
    cout<<ans<<'\n';
    return 0;
    
}