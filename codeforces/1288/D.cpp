#include<bits/stdc++.h>
#define MOD  1000000007
#define ll long long int 
#define pii pair<int,int>
#define uu first
#define vv second

const int MAX = 3e5 +5;
using namespace std;
int ara[MAX][10] ;
pii rec[10000];
int n , m;

pii solve(int tgt) {

    memset(rec , -1 , sizeof rec);
    
    for(int i =0 ; i < n ; i++ ) {
        
        int mask = 0;
        for(int j =0 ; j < m ; j++) {
            if(ara[i][j] >= tgt) mask |= (1<<j);
        }
        rec[mask] = {1 , i};
    }
    
    int mm = (1<<m);
    
    for (int i =0 ; i < mm ; i++ ) {
        
        if(rec[i] == pii(-1,-1) ) continue;
        
        for(int j = 0 ; j < mm ; j++ ) {
            
            if(rec[j] == pii(-1,-1) ) continue;
            
            if( (i | j) != mm-1 ) continue;
            
            return {rec[i].vv+1 , rec[j].vv+1};
        }
    }
    return {-1,-1};
    
}


int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin>>n>>m;
    
    
    for(int i = 0 ; i < n ; i++ ) {
        for(int j =0 ; j < m ;j++ ) cin>>ara[i][j];
    }
    
    int lo = 0 , hi = 1e9+ 10;
    pii ans ={-1 , -1};
    
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        
        pii ret = solve(mid);
        if(ret == pii(-1,-1) ) hi = mid-1;
        else {
            ans = ret;
            lo = mid+1;
        }
    }
    cout<<ans.uu<<" "<<ans.vv<<'\n';
    return 0;
}