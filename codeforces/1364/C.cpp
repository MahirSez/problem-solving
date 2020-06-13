#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6;

int main()
{
    fastRead;
    int n;
    cin>>n;
    vector<int>vec(MAX), rec(MAX, -1);
    
    for(int i =0 ; i < n ; i++ ) {
        cin>>vec[i];
        rec[vec[i]] = i;
    }
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(int i = 0 ; i < MAX ; i++ ) {
        if(rec[i] == -1) pq.push(i);
    }
    
    vector<int>ans(n);
    
    for(int i =0 ; i < n ; i++ ) {
        
        if(pq.empty()) {
            cout<<-1<<'\n';
            return 0;
        }
        
        ans[i] = pq.top();
        pq.pop();
        
        if(rec[vec[i]] ==i ) pq.push(vec[i]);
    }
    
    vector<int>mex(n), mark(n);
    
    int now = 0;
    
    for(int i =0 ; i < n ; i++ ) {
        
        mark[ans[i]] = 1;
        while(mark[now] == 1) now++;
        if(now!= vec[i]) {
            cout<<-1<<'\n';
            return 0;
        }
    }
    for(auto x : ans)  cout<<x<<" ";
    cout<<'\n';
    return 0;
    
    
    
    
}