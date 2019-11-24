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
priority_queue<int, vector<int> , greater<int> > pq;
int vis[MAX] , ans[MAX];

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n;
        cin>>n;

        for(int i =1; i <=n ; i++ ) pq.push(i) , vis[i] = 0;

        
        bool ok = 1;
        
        for(int i= 1; i <=n ; i++ ) {
            
            int in;
            cin>>in;
            if(vis[in] == 0 ) {
                vis[in] = 1;
                ans[i] = in;
                continue;
            }
            while(!pq.empty() && vis[pq.top()] ) pq.pop();
            
            if(pq.empty() || pq.top() > in) {
                ok= 0 ;
                continue;
            }
            
            vis[pq.top()] = 1;
            ans[i] = pq.top();
            pq.pop();
        }
        
        if(!ok) cout<<-1<<'\n';
        else {
            
            for(int i =1; i <=n ; i++) cout<<ans[i]<<" ";
            cout<<'\n';
        }
        while(!pq.empty()) pq.pop();
        
    }
    return 0;
    
}