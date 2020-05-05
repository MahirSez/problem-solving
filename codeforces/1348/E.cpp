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

int main()
{
    fastRead;
    int n , k;
    cin>>n>>k;
    vector<int>a(n+1) , b(n+1) ;
    vector<ll> tot(n+1);
    
    
    vector< vector<int > >last(k , vector<int>(k ) );
    
    for(int i =1 ;i <=n ; i++ ) cin>>a[i]>>b[i] , tot[i] += a[i] + b[i] + tot[i-1];
    
    last[0][0] = 1;
    
    for(int i =1 ; i <=n ; i++ ) {
        
        int extra = (a[i] + b[i])%k;
        
        vector< vector<int> >now(k , vector<int>(k) );
        
        for(int b_extra = 0 ; b_extra <= min(k -    1, b[i]) ; b_extra++ ) {
            
            int a_extra = (extra - b_extra + k)%k;
            if(a_extra > a[i]) continue;
            
            int prev_extra = tot[i-1]%k;
            
            for(int aa = 0 ; aa < k  ; aa++ ) {
                
                int bb = (prev_extra - aa + k)%k;
                now[(aa + a_extra)%k][(bb + b_extra)%k] |= last[aa][bb];
            }
        }
        last = now;
    }
    
    int baad = INF;
    for(int i = 0 ;i <k ; i++ ) {
        for(int j =0 ;j <k ; j++ ) {
            if(last[i][j] ==0 ) continue;
            baad = min(baad , i+j);
        }
    }
    assert( (tot[n]-baad)%k == 0);
    cout<<(tot[n]-baad)/k<<'\n';
    return 0;
}