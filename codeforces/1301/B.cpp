#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n;
        cin>>n;
        vector<ll>vec(n);
        
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        
        ll  cnt = 0;
        
        ll mn = INF , mx = -INF;
        
        for(int i = 0 ; i < n ; i++ ) {
            
            if(vec[i] != -1) continue;
            
            if(i > 0 && vec[i-1] != -1 ) {
                mn = min(mn , vec[i-1]) , cnt++;
                mx = max(mx , vec[i-1]);
            } 
            if( i < n-1 && vec[i+1] != -1) {
                mx = max(mx , vec[i+1]) , cnt++;
                mn = min(mn , vec[i+1]);
            }
        }
        
        ll tgt = (mn + mx)/2;
        ll m = -INF;
        
        
        for(int i =0 ; i < n ; i++ ) if(vec[i] == -1) vec[i] = tgt;
        
        for(int i = 1 ; i < n ; i++ ) {
            m = max(m , abs(vec[i] - vec[i-1] ) ) ;
        }
    
        
        cout<<m<<" "<<tgt<<'\n';
    }
    return 0;
}


/*
1
7
1 -1 7 5 2 -1 5
*/