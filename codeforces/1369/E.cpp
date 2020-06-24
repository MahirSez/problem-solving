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
vector<int>edg[MAX], rev[MAX];
int main()
{
    fastRead;
    int n, m;
    cin>>n>>m;
    vector<int>wt(n+1), taken(n+1), people(m+1), deg(n+1);
    for(int i =1 ; i<=n ; i++ ) cin>>wt[i];
    
    for(int i =1; i <=m ; i++) {
        int u, v;
        cin>>u>>v;
        edg[i].push_back(u);
        edg[i].push_back(v);
        rev[u].push_back(i);
        rev[v].push_back(i);
        deg[u]++;
        deg[v]++;
    }
    
    vector<int>ans;
    queue<int>q;
    for(int i =1 ; i <=n ; i++ ) {
        if(wt[i] >= deg[i]) {
            taken[i] = 1;
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        
        for(auto x : rev[top]) {
            if(people[x]) continue;
            people[x] = 1;
            ans.push_back(x);

            for(auto xx : edg[x]) {
                deg[xx]--;
                if(taken[xx] ==0 && wt[xx] >= deg[xx] ) {
                    taken[xx] = 1;
                    q.push(xx);
                }
            }
        }
    }
    if(ans.size() != m) {
        cout<<"DEAD\n";
        return 0;
    }
    cout<<"ALIVE\n";
    reverse(ans.begin(), ans.end());
    
    for(int x : ans) cout<<x<<" ";
    cout<<'\n';
    return 0;
}