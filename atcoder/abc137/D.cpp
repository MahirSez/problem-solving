#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
    

vector<int>edg[MAX];
int n , m;


int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < n ; i++ ) {
        int a , b;
        cin>>a>>b;
        
        edg[a].push_back(b);
    }
    
    priority_queue<int>pq;
    
    int ans = 0;
    
    for(int i = m-1 ; i>=0 ; i-- ) {
        
        
        int gap = m - i;
        
        for(auto x : edg[gap]) pq.push(x);
//        cout<<gap<<" "<<pq.size()<<endl;
        
        if( !pq.empty() ) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout<<ans<<endl;
    return 0;
}