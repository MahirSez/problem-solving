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




int deg[MAX];

int  taken[30] , edg[30][30];

vector<int>nxt[30];

string ans = "";

void dfs(int node) {
    
    
    taken[node] = 1;
    ans += char(node + 'a');
    
    for(auto x : nxt[node]) {
        
        if( taken[x] ) continue;
        
        dfs(x);
        break;
    }
}



int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        
        string str;
        cin>>str;
        int n = str.size();
        memset(edg , 0 , sizeof edg);
        
        for(int i = 0 ; i < 30 ; i++ )  deg[i] = 0 , taken[i] = 0 , nxt[i].clear();
        for(int i = 1 ; i < n ; i++ ) {
            
            int id1 = str[i]-'a';
            int id2 = str[i-1]  -'a';
            
            if(id1 > id2) swap(id1 , id2);
            
            if(edg[id1][id2] ==0 ) {
                deg[id1]++;
                deg[id2]++;
                
                
                nxt[id1].push_back(id2);
                nxt[id2].push_back(id1);
                
                edg[id1][id2] = 1;
                edg[id2][id1] = 1;
            }
        }
        bool ok = 1;
        
        for(int i = 0 ; i < 30 ; i++ ) {
            if(deg[i] > 2) ok = 0;
        }
        
        if(!ok) {
            cout<<"NO\n";
            continue;
        }
        
        
        ans = "";
        
        for(int i =0 ; i < 26 ; i++ ) {
            
            if(taken[i] || deg[i] == 2 ) continue;
            
            if(deg[i] == 0) {
                ans += char(i + 'a');
                taken[i] = 1;
                continue;
            }
                
            dfs(i );
        }
        
        if(ans.size() != 26) cout<<"NO\n";
        else {
            cout<<"YES\n";
            cout<<ans<<'\n';
        }
    }
    return 0;
}