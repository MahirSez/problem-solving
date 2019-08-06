#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int const MAX = 1e6 + 6;

int n , m;
int ara[2000][2000] , pt[2000];


int cnt[2000] ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i =0 ; i < n ; i++ ) {
        
        string str;
        cin>>str;
        for(int j =0 ; j < m ; j++ ) {
            
            ara[i][j] = str[j] - 'A';
        }
    }
    for(int i =0 ; i < m ; i++ ) cin>>pt[i];
    
    ll ans = 0;
    
    
    for(int i =0 ; i < m ; i++ ) {
        
        
        memset(cnt , 0 , sizeof cnt);
        
        for(int j = 0; j < n ; j++ ) {
            
            cnt[ara[j][i]]++;
        }
        
        
        ll tmp = 0;
        for(int j =0 ; j < 5 ; j++ ) {
            
            
//            cout<<i<<" -- "<<j<<" "<<cnt[j]<<endl;
            tmp = max(tmp , 1LL*cnt[j]*pt[i]);
        }
        
        ans += tmp;
    }
    
    cout<<ans<<endl;
    return 0;
}