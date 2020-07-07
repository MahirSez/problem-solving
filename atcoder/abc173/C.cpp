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
int ara[10][10];

int main()
{
    fastRead;
    int n, m , k;
    cin>>n>>m>>k;
    
    for(int i =0 ; i < n ; i++ ) {
        string str;
        cin>>str;
        for(int j =0 ; j < m ; j++ ) {
            if(str[j] == '#') ara[i][j] = 1;
        }
    }
    
    int ans = 0;
    
    for(int i =0  ;i < (1<<n) ; i++ ) {
        
        for(int j =0 ; j < (1<<m) ; j++ ) {
            
            int cnt = 0;
            for(int ii = 0 ; ii < n ; ii++ ) {
                for(int jj =0 ; jj < m ; jj++ ) {
                    
                    if(ara[ii][jj] == 0) continue;
                    
                    if( (i &(1<<ii)) || (j &(1<<jj)) ) continue;
                    cnt++;
                }
            }
            if(cnt == k) ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}