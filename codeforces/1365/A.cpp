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
int ara[100][100];
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        for(int i =0 ; i < n ; i++ ) {
            for(int j =0 ; j < m ; j++ ) cin>>ara[i][j];
        }
        int ro = 0 ,col = 0;
        for(int i =0 ; i < n ; i++) {
            bool ok =1;
            for(int j = 0; j < m ; j++ ) {
                if(ara[i][j]) ok = 0;
            }
            if( ok) ro++;
        }
        
        for(int i =0 ; i < m ; i++) {
            bool ok =1;
            for(int j = 0; j < n ; j++ ) {
                if(ara[j][i]) ok = 0;
            }
            if( ok) col++;
        }
        int tmp = min(col,ro);
        if(tmp%2) cout<<"Ashish\n";
        else cout<<"Vivek\n";
    }
    return 0;
}