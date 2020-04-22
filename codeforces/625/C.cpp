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
    fastRead;
    int n , k;
    cin>>n>>k;
    int now = 0;
    
    for(int i = 1 ; i <=n ; i++ ) {
        
        for(int j = 1 ; j < k ; j++) {
            ara[i][j] = ++now;
        }
    }
    
    for(int i = 1 ; i <=n ; i++) {
        for(int j = k ; j <=n ; j++ ) {
            ara[i][j] = ++now;
        }
    }
    
    ll sum = 0;
    for(int i =1 ; i <=n ; i++ ) sum += ara[i][k];
    
    cout<<sum<<'\n';
    for(int i =1 ; i <=n ; i++ ) {
        for(int j =1 ; j <=n ;j++ ) {
            cout<<ara[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}