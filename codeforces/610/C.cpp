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
int ara[600][600];

int main()
{
    int n;
    cin>>n;
    memset(ara , -1 , sizeof ara);
    
    ara[1][1] = 1;
    
    
    for(int p = 1 ; p <= n ; p++ ) {
        
        int pr1 = 1;
        int pr2 = (1<<(p-1));
        
        int pc1 = 1;
        int pc2 = pr2;
        
        
        int r1 = 1 , r2 = pr2;
        int c1 = pc2 + 1 , c2 = (1<<p);
//        
//        cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<'\n';
//        
//        cout<<pr1<<" "<<pr2<<" "<<pc1<< " "  <<pc2<<'\n';
        
        
        for(int i = r1 , j = pr1 ; i <= r2 ; i++,j++ ) {
            
            for(int k = c1 , l = pc1 ; k <= c2 ; k++, l++ ) {
                
                ara[i][k] = ara[j][l];
//                cout<<" "<<i<<" "<<k<<"-- "<<j<<" "<<l<< " "<<ara[i][k]<<'\n';
            }
            
        }
        
        r1 = pr2 + 1 , r2 = (1<<p);
        c1 = 1 , c2 = pc2;
        
        for(int i = r1 , j = pr1 ; i <= r2 ; i++,j++ ) {
            
            for(int k = c1 , l = pc1 ; k <= c2 ; k++, l++ ) {
                
                ara[i][k] = ara[j][l];
            }
            
        }
        
        c1 = r1  , c2 = r2;
        for(int i = r1 , j = pr1 ; i <= r2 ; i++,j++ ) {
            
            for(int k = c1 , l = pc1 ; k <= c2 ; k++, l++ ) {
                
                ara[i][k] = 1^ ara[j][l];
            }
            
        }
        
    }
    
    for(int i =1; i <=(1<<n) ; i++ ) {
        for(int j =1 ;j <=(1<<n) ; j++ ) {
            if(ara[i][j]) cout<<"+";
            else cout<<"*";
//            cout<<ara[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
