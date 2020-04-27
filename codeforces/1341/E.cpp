#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;


int dist[10004][1002];

int main()
{
    fastRead;
    
    int n , m;
    cin>>n>>m;
    vector<int>vec(m);
    for(int i =0  ; i < m ; i++ ) cin>>vec[i];
    
    sort(vec.begin() , vec.end());
    
    memset(dist , - 1, sizeof dist);
    
    ll r , g;
    cin>>g>>r;
    
    
    deque<pii>dq;
    dist[0][0] = 0;
    
    dq.push_front({0,0});
    
    ll ans = INF;
    
    while(!dq.empty()) {
        
        int topid = dq.front().uu;
        int _time = dq.front().vv;
        dq.pop_front();
        
        if(_time == 0 ) {
            
            int more = n - vec[topid];
            if(more <= g ) {
                ll tmp = 1LL* dist[topid][0] *(r+g) + more;
                ans = min(tmp , ans);
            }
        }
        if( _time == g) {
            
            if(dist[topid][0] ==-1 ) {
                dist[topid][0] = dist[topid][g] + 1;
                dq.push_back({topid , 0});
            }
            continue;
        }
        
        if(topid > 0) {
            
            int gap = vec[topid] - vec[topid-1] ;
            if(gap + _time <= g && dist[topid-1][gap+_time] == -1) {
                
                dist[topid-1][gap + _time] = dist[topid][_time] ;
                dq.push_front({topid-1 , gap + _time});
            }
            
        }
        if(topid < m-1 ) {
            
            int gap = vec[topid+1] - vec[topid] ;
            if(gap + _time <= g && dist[topid+1][gap+_time] == -1) {
                
                dist[topid+1][gap + _time] = dist[topid][_time] ;
                dq.push_front({topid+1 , gap + _time});
            }
        }
        
 
    }
    if(ans  == INF) cout<<-1<<'\n';
    else cout<<ans<<'\n';
    return 0;
    
    
}