#include<bits/stdc++.h>
using namespace std;

int const MAX  = 1e5+6;
int n , u[MAX] , v[MAX] , m , q , z[MAX] , x[MAX] , y[MAX] ,ans[MAX] , lo[MAX] , hi[MAX];
int par[MAX] , sz[MAX];


vector<int>rec[MAX];

int boss(int x) {
    
    return ( par[x] == x) ? x : ( par[x] = boss(par[x]) );
//    if(par[x] == x ) return x;
//    return par[x] = boss(par[x]);
}


void solve() {

    for(int i =1 ; i <=q ; i++ ) lo[i] = 1 , hi[i] = m;
    memset(ans, -1 , sizeof ans);
    
    while(1)    {     
            
        for(int i =1;  i <=m ; i++) rec[i].clear();
        
        for(int i = 1 ; i<=n ; i++ ) par[i] = i , sz[i] = 1;
        
    
        bool ok = true;
        
        for(int i =1 ; i <=q ; i++ ) {
            
            if( lo[i] > hi[i] ) continue;
            int mid = (lo[i] + hi[i])/2;
            rec[mid].push_back(i);
            ok = false;
        }
        
        if( ok )  return;
        
        for(int i =1 ; i <=m ; i++ ) {
            
            int parU = boss(u[i]);
            int parV = boss(v[i]);
            
            if( parU != parV ) {
                
                par[parV] = parU;
                sz[parU] += sz[parV];
            }
            
            for(auto id : rec[i]) {
                
                
                int parX = boss(x[id]);
                int parY = boss(y[id]);
                
                
                int tmp = sz[parX];
                
                if(parX != parY) tmp += sz[parY];
                
                if( z[id] <= tmp ) {
                    hi[id] = i-1;
                    ans[id] = i;
                }
                else if( z[id] > tmp ) {
                    lo[id] = i+1;
                }
            }
        }
        
        
    }

    
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    
    for(int i =1 ; i <= m  ; i++ ) cin>>u[i]>>v[i];
    
    cin>>q;
    for(int  i =1 ; i <= q ; i++ ) cin>>x[i]>>y[i]>>z[i];
    
    solve();
    
    
    for(int i =1 ; i <= q ; i++ ) cout<<lo[i]<<'\n';
    return 0;
}

