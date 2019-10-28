#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const ll MOD = 1e9+7;

int n , m;
ll ara[3000][3000] ;
ll dpr[3000][3000] , dpc[3000][3000] ;
ll cumr[3000][3000] , cumc[3000][3000];
ll dpcumr[3000][3000] , dpcumc[3000][3000];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    
    for(int i = 1 ; i<=n ; i++ ) {
        string str;
        cin>>str;
        for(int j =1  ; j<=m ; j++ ) {
            if(str[j-1] == 'R') ara[i][j] = 1;
        }
    }
    
    for(int i =n; i >=1 ; i-- ) {
        for(int j = m; j >=1 ; j-- ) {
            cumr[i][j] = ara[i][j] + cumr[i][j+1];
            cumc[i][j] = ara[i][j] + cumc[i+1][j];
        }
    }
    
//    for(int i =1 ; i <=n ; i++ ) {
//        for(int j =1; j <= m  ;j++ ) {
//            cout<<cumc[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
    
    dpr[n][m] = dpc[n][m] = dpcumc[n][m] = dpcumr[n][m] = 1;
    
    for(int i =n;  i>=1 ; i-- ) {
        for(int j =m;  j>=1 ; j-- ) {
            
            if(i == n && j ==m ) continue;
            
            int rocks = cumr[i][j+1];
            
            
            int frm  = j+1 , to = m - rocks;
            
            dpr[i][j] = ( dpcumc[i][frm] - dpcumc[i][to+1] + MOD )%MOD;

//            for(int k = frm ; k <=to ; k++ ) {
//                    
//                dpr[i][j] += dpc[i][k];
//            }
            
            
            rocks = cumc[i+1][j];
            frm = i+1 , to = n - rocks;
            
            dpc[i][j] = (dpcumr[frm][j] - dpcumr[to+1][j] + MOD )%MOD;

//            for(int k = frm ; k <=to ; k++ ) {
//                dpc[i][j] += dpr[k][j];
//            }
            
//            cout<<i<<" "<<j<<" -- "<<dpr[i][j]<<" "<<dpc[i][j]<<'\n';
            
            dpcumr[i][j] = (dpr[i][j] + dpcumr[i+1][j])%MOD;
            dpcumc[i][j] = (dpc[i][j] + dpcumc[i][j+1])%MOD;
            
        }
    }
    if(n ==1 && m ==1 ) cout<<1<<'\n';
    else cout<<( (dpc[1][1] + dpr[1][1])%MOD )<<'\n';
    
    return 0;
}