#include<bits/stdc++.h>
#define MAX 1000006
#define ll long long int
using namespace std;
int n , m ;
ll ara[4000][4000] ;
ll dp[4][2000][2000];


ll solve(int id , int x , int y) {

    if( x < 0 || y < 0 || x >= n || y >= m) return -1e18;

    if( id ==0 && x == 0 && y ==0)  return ara[x][y];
    if( id == 3 && x == n-1 && y == m-1) return ara[x][y];
    
    if( id == 1 && x== n-1 && y ==0  ) return ara[x][y];
    if( id==2 && x==0 && y== m-1) return ara[x][y];


    ll &ret = dp[id][x][y];
    if( ret != -1) return ret ;

    ret = 0;

    if( id == 0 ) ret = max( solve(id , x-1 , y) , solve(id ,x, y-1 ) );
    if( id == 3 ) ret = max( solve(id , x+1 , y) , solve(id ,x , y+1 ) );
    
    
    if( id == 1 ) ret = max( solve(id , x+1 , y) , solve(id ,x , y-1 ) );
    if( id == 2 ) ret = max( solve(id , x-1 , y) , solve(id ,x,  y+1 ) );
    
    ret += ara[x][y];
    return ret ;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    for(int i = 0 ; i  < n ; i++) {

        for(int j =0 ; j < m ; j++ ) {

            cin>>ara[i][j];
        }
    }

    memset(dp , -1 , sizeof dp);

    ll ans = 0;

    for(int i = 0 ; i  < n ; i++) {

        for(int j =0 ; j < m ; j++ ) {

            ans = max(ans , solve(0,i-1,j) + solve(3,i+1,j) + solve(1,i,j-1) + solve(2,i,j+1)  );
            ans = max(ans , solve(0 ,i , j-1 ) + solve(3 , i , j+1 ) + solve( 1 , i+1 , j) + solve(2 , i-1 , j ) ) ;
        }
    }

    cout<<ans<<'\n';
    return 0;


}