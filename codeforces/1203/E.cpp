#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int n , ara[MAX] , rec[MAX];


int main()
{
    cin>>n;
    for(int i =0 ; i < n ;i++ ) cin>>ara[i];
    
    sort(ara , ara + n );
    
    if(ara[0]  > 1 )  {
        ara[0]--;
        
    }
    rec[ara[0]] = 1;
    rec[0] = 1;
    
    
    for(int i =1 ; i < n ; i++ ) {
        
        
        if( rec[ara[i]-1] ==0 ) {
            
            ara[i]--;
            rec[ara[i]] = 1;
        }
        else if(rec[ara[i]] ==0 ) {
            rec[ara[i]] = 1;
        }
        else if( rec[ara[i] + 1] ==0 ) {
            ara[i]++;
            rec[ara[i]] = 1;
        }
    }
    
    
    int ans = 0;
    for(int i =1 ; i < MAX ; i++ )  {
        if(rec[i] ) ans++;
    }
    cout<<ans<<'\n';
    return 0;
    
    
}