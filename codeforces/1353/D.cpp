#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int ans[MAX];

struct comp {
    
    bool operator() (pii &p1 , pii & p2) {
        if(p1.vv - p1.uu == p2.vv - p2.uu) return p1.uu > p2.uu;
        return p1.vv - p1.uu < p2.vv - p2.uu;
    }
};
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n ;
        cin>>n;
        priority_queue<pii , vector<pii> , comp>pq;
        pq.push({0 , n-1});
        int cnt = 0;
        while(!pq.empty()) {
            int l = pq.top().uu;
            int r = pq.top().vv;
            
            pq.pop();
            if( l > r) continue;
            
            int mid = (l+r)/2;
            ans[mid] = ++cnt;
            pq.push({l , mid-1});
            pq.push({mid+1 , r});
        }
        for(int i =0 ; i < n ; i++ ) cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
  
    return 0;
}