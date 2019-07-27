#include<bits/stdc++.h>
#define MAX 200005
#define ll long long int
#define pii pair<ll,ll>
#define pip pair<ll,pii>
#define uu first
#define vv second
 
 
using namespace std;
int n , m , k;
vector<pii>edg[MAX];
map<int , int>mp;

ll dist[900][900];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m>>k;
    vector<pip>vec;
    
    
    for(int i = 0 ; i < m ; i++ ) {
        
        int u , v , w;
        cin>>u>>v>>w;
        edg[u].push_back({v,w});
        edg[v].push_back({u ,w});
        vec.push_back({w , {u,v} });
    }
    sort(vec.begin() , vec.end());
    
    
    int id = 0;
    
    for(int i =0 ; i< min((int)vec.size() , k ) ; i++ ) {
        
        int u = vec[i].vv.uu;
        int v = vec[i].vv.vv;
        
        int w = vec[i].uu;
        
        if( mp.count(u) ==0 ) mp[u] = ++id;
        if( mp.count(v) ==0 ) mp[v] = ++id;
        
        dist[mp[u]][mp[v]] = w;
        dist[mp[v]][mp[u]] = w;
    }
    
    for(int i = 1 ; i <=id ; i++ ) {
        
        for(int j =1 ; j <=id ; j++ ) {
            
            dist[i][j] = ((dist[i][j] == 0) ? 1E18 : dist[i][j] );
            
//            cout<<i<<" "<<j<<" "<<dist[i][j]<<endl;
        }
    }
    
    
    
    
    for(int i =1 ; i <=id ; i++ ) {
        for(int j =1 ; j <=id ; j++  ) {
            for(int k= 1 ;k <=id ; k++ ) {
                
                dist[j][k] = min(dist[j][k] , dist[j][i] + dist[i][k]);
            }
        }
    }
    
    vector<ll>ans;
    for(int i = 1;  i <=id ; i++ ) {
        for(int j =i+1 ; j<= id ; j++ ) {
            
            ans.push_back(dist[i][j]);
        }
    }
    
    sort(ans.begin() , ans.end() ) ;
    cout<<ans[k-1]<<'\n';
    
    
    return 0;
    
    
}