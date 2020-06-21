#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         2e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 3e3 + 5;

vector<int>edg[MAX],  lvl[MAX];
int mark[MAX];
int mx;

pii ask(vector<int>vec) {
    
    cout<<"? "<<vec.size()<<" ";
    for(auto x : vec ) cout<<x<<" ";
    cout<<endl;
    int a, b;
    cin>>a>>b;
    return {a,b};
}

void dfs(int node ,int p, int l) {
    
    mx = max(mx, l);
    lvl[l].push_back(node);
    for(auto x : edg[node]) {
        if(x == p ) continue;
        dfs(x, node, l+1);
    }
}

int dfs1(int node, int p, int tgt) {
    
    if(node == tgt) return mark[node] = 1;
    
    int ret = 0;
    for(auto x : edg[node])  {
        if( x == p) continue;
        ret |= dfs1(x, node, tgt);
    }
    return mark[node] = ret;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        memset(mark, 0 , sizeof mark);
        for(int i =0; i <=n ; i++) edg[i].clear(), lvl[i].clear();
        mx = 0;
        
        for(int i =1 ; i < n ; i++ ) {
            int u, v;
            cin>>u>>v;
            edg[u].push_back(v);
            edg[v].push_back(u);
        }
        
        vector<int>tmp;
        for(int i =1 ; i <=n ; i++ ) tmp.push_back(i);
        pii ret = ask(tmp);
        
        int rt = ret.uu;
        int dst = ret.vv;
        dfs(rt, -1, 0);
        
        int lo = dst/2, hi = mx, tgt = -1, tgtDst = -1;
        while(lo <=hi ) {
            int mid = (lo+hi)/2;
            ret = ask(lvl[mid]);
            if(ret.vv == dst) {
                tgt = ret.uu;
                tgtDst = mid;
                lo = mid + 1;
            }
            else hi = mid -1;
        }
        
        dst -= tgtDst;
        
        
        dfs1(rt, -1, tgt);
        
        tmp.clear();
        for(auto x : lvl[dst] ) {
            if(mark[x] == 0) tmp.push_back(x);
        }
        if(tmp.empty()) tmp.push_back(lvl[dst][0]);
        
        ret = ask(tmp);
        cout<<"! "<<tgt<<" "<<ret.uu<<endl;
        string s;
        cin>>s;
        if(s != "Correct") break;
        
    }
    return 0;
}
