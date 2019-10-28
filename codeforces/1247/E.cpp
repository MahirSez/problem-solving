#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const ll MOD = 1e9+7;

int n , m;
ll ara[3000][3000] ;
ll dpr[3000][3000] , dpc[3000][3000] ;
ll cumr[3000][3000] , cumc[3000][3000];
ll dpcumr[3000][3000] , dpcumc[3000][3000];


ll add(ll a , ll b) {
    return (a+ b <  MOD) ? (a+b) : (a+b - MOD);
}
ll sub(ll a , ll b) {
    return add(a , MOD - b);
}

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
    
    
    dpr[n][m] = dpc[n][m] = dpcumc[n][m] = dpcumr[n][m] = 1;
    
    for(int i =n;  i>=1 ; i-- ) {
        for(int j =m;  j>=1 ; j-- ) {
            
            if(i == n && j ==m ) continue;
            
            int rocks = cumr[i][j+1];
            
            
            int frm  = j+1 , to = m - rocks;
            
            dpr[i][j] = sub( dpcumc[i][frm] , dpcumc[i][to+1]  );
            
            
            rocks = cumc[i+1][j];
            frm = i+1 , to = n - rocks;
            
            dpc[i][j] = sub(dpcumr[frm][j] , dpcumr[to+1][j]) ;

            dpcumr[i][j] = add(dpr[i][j] , dpcumr[i+1][j]) ;
            dpcumc[i][j] = add(dpc[i][j] , dpcumc[i][j+1]) ;
            
        }
    }
    if(n ==1 && m ==1 ) cout<<1<<'\n';
    else cout<< add(dpc[1][1] , dpr[1][1]) <<'\n';
    
    return 0;
}