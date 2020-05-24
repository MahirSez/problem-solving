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
        int n;
        cin>>n;
        
        for(int i = 0 ; i <=n ; i++  ) {
            ara[i][n] = 1;
            ara[n][i] = 1;
        }
        for(int i =0 ; i <n ; i++ ) {
            string str;
            cin>>str;
            for(int j = 0 ; j < n ; j++ ) {
                if(str[j]=='1') ara[i][j] = 1;
                else ara[i][j] = 0;
            }
        }
//        for(int i = 0 ; i <=n ; i++ ) {
//            for(int j =0 ; j <=n ; j++ ) {
//                cout<<ara[i][j];
//            }
//            cout<<'\n';
//        }
//        cout<<'\n';
        bool ok  = 1;
        for(int i =0 ; i < n ;i++ ) {
            for(int j = 0 ; j < n ; j++ ) {
                if(ara[i][j] == 0 ) continue;
                if(ara[i+1][j]==0 && ara[i][j+1] == 0 ) ok = 0;
            }
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    
}