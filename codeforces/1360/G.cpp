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
int ara[60][60] , roCnt[60] , colCnt[60];
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n , m , a , b;
        cin>>n>>m>>a>>b;
        memset(ara , 0 , sizeof ara);
        memset(roCnt , 0 , sizeof roCnt);
        memset(colCnt , 0 , sizeof colCnt);
        
        for(int i =0 ; i < n ; i++ ) {
            
            for(int aa = 0 ; aa < a ;aa++ ) {
                
                int mnId = -1 , cnt = INF;
            
                for(int j =0 ; j < m ; j++ ) {
                    if(ara[i][j]) continue;
                    if(colCnt[j] < cnt ) {
                        cnt = colCnt[j];
                        mnId = j;
                    }
                }
                
                if(mnId == -1) continue;
                ara[i][mnId] = 1;
                roCnt[i]++;
                colCnt[mnId]++;
            }
        }
        bool ok = 1;
        for(int i =0 ; i < n ; i++ ) {
            if(roCnt[i] != a) ok = 0;
        }
        for(int i =0 ; i < m ; i++ ) {
            if(colCnt[i] != b) ok = 0;
        }
        if(!ok) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i =0 ; i < n ; i++ ) {
            for(int j =0 ; j < m ; j++ ) {
                cout<<ara[i][j];
            }
            cout<<'\n';
        }        
    }
    return 0;
}
