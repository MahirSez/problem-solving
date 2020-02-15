#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

ll n , now;


/*
1
3 0
5 1 2
7 3 5
10 -1 0
*/


int main()
{
    fastRead;
    int tt;
    cin>>tt;
    while(tt--) {
        
        
        cin>>n>>now;    
        ll curL = now , curH = now;
        
        ll curTime = 0;
        
        bool ok = 1;
        
        for(int i =0 ; i < n ; i++ ) {
            
            
            ll t , l , h;
            
            cin>>t>>l>>h;
            
            ll diff = t - curTime;
            
            ll hmax = curH + diff;
            ll hlow = curH - diff;
            
            ll lmax = curL + diff;
            ll llow = curL - diff;
            
//            cout<<"h "<<h<<" "<<hmax<<" "<<hlow<<'\n';
//            cout<<"l "<<l<<" "<<lmax<<" "<<llow<<'\n';
            
            
//            if(h < hlow || h > hmax) ok = 0;
//            if( l < llow || l > lmax) ok = 0;
            
            
            curH = min( hmax , h);
            
            curL = max( llow , l);
            
            if(curL > curH) ok = 0;
            
//            cout<<curH<<" "<<curL<<'\n';
            
            
            curTime = t;
        }
        
        if(ok ) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    
    return 0;
    
}