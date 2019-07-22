#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         2e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , k , ara[MAX];
set<int>st;
int main()
{
    fastRead;
    cin>>n>>k;
    for(int i =1 ; i <= n ; i++ ) {
        cin>>ara[i];
    }
    
    
    priority_queue<int, vector<int> ,greater<int> > pq;
    
    for(int i = 1 ; i <=n ; i++) {
        
        pq.push(ara[i] - ara[i+1]);
    }
    ll ans = ara[n] - ara[1];
    
    while( !pq.empty()  ) {
        
        
        if(k == 1) break;
        k--;
        ans += pq.top();
        pq.pop();
    }
    
    cout<<ans<<'\n';
    
    
    return 0;   
}


/*
5 3
1 6 10 12 20
*/