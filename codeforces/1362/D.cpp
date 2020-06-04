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

vector<int>edg[MAX] , rec[MAX];

int col[MAX], cnt[MAX];

bool ok(int node, int tgt) {
    
    int baki = tgt-1;
    
    for(auto x : edg[node]) {
        if(col[x]==0) continue;
        if(col[x] == tgt) {
            baki = -1;
            continue;
        }
        if(cnt[col[x]] ==0 ) {
            baki--;
            cnt[col[x]] = 1;
        }
    }
    for(auto x : edg[node]) cnt[col[x]] = 0;
    return (baki == 0);
    
}


int main()
{
    fastRead;
    
    int n, m;
    cin>>n>>m;
    
    for(int i =1 ; i <=m ; i++ ) {
        
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    for(int i =1 ; i <=n ; i++ ) {
        int tmp;
        cin>>tmp;
        rec[tmp].push_back(i);
    }
    
    vector<int>ans;
    
    for(int i =1 ; i <=n; i ++ ) {
        
        for(auto x : rec[i]) {
            
            bool ret = ok(x, i);
            
            if(ret == 0 ) {
//                cout<<x<<" "<<i<<'\n';
                cout<<-1<<'\n';
                return 0;
            }
            col[x] = i;
            ans.push_back(x);
        }
    }
    
    for(auto x : ans) cout<<x<<" ";
    cout<<'\n';
    return 0;
    
    
}