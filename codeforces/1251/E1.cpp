#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
  
  
const int MAX = 2e5 + 5;
vector<ll>rec[MAX];
ll sum[MAX];
int main()
{
    
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n ;
        cin>>n;
        for(int i =0 ; i <n ; i++ ) rec[i].clear();
        
        for(int i =0 ; i < n ; i++ ) {
            int m , p;
            cin>>m>>p;
            rec[m].push_back(p);
        }
        
        sum[0] = rec[0].size();
        
        for(int i =1 ; i < n ; i++ ) sum[i] = sum[i-1] + rec[i].size();
        
        priority_queue<ll , vector<ll> , greater<ll> > pq;
        
        int niche = 0;
        ll ans = 0;
        
        for(int i = n-1 ; i>0 ; i-- ) {
            
            for(auto x : rec[i]) pq.push(x);
            
            int upore = sum[i-1];
            
            while(upore + niche < i) {
                ans += pq.top();
                pq.pop();
                niche++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}