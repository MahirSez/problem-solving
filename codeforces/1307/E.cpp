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

const int MAX = 5e3 + 6;
int n , m , ara[MAX];
int l[MAX][MAX] , r[MAX][MAX];

vector<int>rec[MAX];


int add(int a , int b) {
    if(a + b >= MOD) return a+b-MOD;
    return a+b;
}


pii unite(pll p1 , pll p2) {
    
    if(p1.uu == p2 .uu) return {p1.uu , add(p1.vv , p2.vv) };
    return max(p1 , p2);
}

int main()
{
    fastRead;
    
    cin>>n>>m;
    for(int i = 1 ; i <=n ; i++ ) cin>>ara[i];
    
    
    for(int i = 1 ; i<=n ; i++ ) {
        
        l[ara[i]][i] = 1;
        
        for(int j =1 ; j <=n ; j++ ) l[j][i] += l[j][i-1];
    }

    
    for(int i = n ; i >=1 ; i-- ) {
        
        r[ara[i]][i] = 1;
        
        for(int j = 1 ; j<=n ; j++ ) r[j][i] += r[j][i+1];
    }
    
    for(int i =1 ; i <=m ; i++ ) {
        int col , val;
        cin>>col>>val;
        rec[col].push_back(val);
    }
    
    for(int i =1; i <=n ; i++ ) sort(rec[i].begin() , rec[i].end());
    
    
    pll ans = {0,0};
    
    for(int pos =0 ; pos <=n ; pos++ ) {
        
        int tmpans = 0 , tmpways= 1;
        
        for(int col =1 ; col <=n ; col++ ) {
                
            int lase = l[col][pos];
            int rase = r[col][pos+1];
            
            int id1 = upper_bound(rec[col].begin() , rec[col].end() , lase ) - rec[col].begin() ;
            int id2 = upper_bound(rec[col].begin() , rec[col].end() , rase ) - rec[col].begin() ;            
            
//            
//            cout<<pos<<" "<<col<<" -> "<<lase<<" "<<rase<<" -- ";
//            cout<<id1<<" "<<id2<<"\n";            
//            
            
            if(ara[pos] == col) {
                
                pll tmp = {0 , 0};
                
                if(id1 > 0  && rec[col][id1-1] == lase) {
                    
                    tmp = {1 , 1};
                    
                    if(id2 < id1 ) {
                        if(id2 > 0) tmp = {2 , id2};
                    }
                    else {
                            
                        if(id2 > 1 ) tmp = {2 , id2-1};
                    }
                }
                
                tmpans = add(tmpans , tmp.uu) ;
                tmpways = (1LL* tmpways * tmp.vv )%MOD;
                continue;
            }
            

            pll tmp = {0,1};
            
            if(id1) tmp = unite(tmp , {1 , id1} );
            if(id2) tmp = unite(tmp , {1 , id2} );
            
            int com = min(id1 , id2);
            int uncom = abs(id1 - id2);
            
            if(com > 0 && com + uncom >=2 ) {
                
                tmp = unite(tmp , { 2 , add(com*uncom , com* (com-1) )  } );
            }
            
            tmpans = add(tmpans , tmp.uu) ;
            tmpways = (1LL* tmpways * tmp.vv )%MOD;
        }
        
        ans = unite(ans , {tmpans , tmpways});
    }
    
    cout<<ans.uu<<" "<<ans.vv<<'\n';
    return 0;
    
    
    
}