#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 5e5 + 6;


vector<int>edg[N];

int vis[N];
stack<int>st;
int ok = 1;

void dfs(int node) {
    vis[node] = 1;
    // cout<<node<<" "<<ok<<'\n';
    if(!ok) return;
    
    for(auto x : edg[node]) {
        // cout<<" -- "<<node<<" "<<x<<'\n';
        if(vis[x] == 0 ) dfs(x);
        else if(vis[x] == 1) {
            ok = 0;
            return;
        }
    }
    vis[node] = 2;
    st.push(node);
}

class Trie {
public:
    vector<vector<int>>trie , en;
    int sz;
    Trie() {
        trie = vector< vector<int> > (N, vector<int>(30) );
        en = trie;
        sz = 0;
    }
    void insert(const string &str, int id) {
        int  v = 0 ;
        for(int i =0 ; i < str.size() ; i++ ) {
            int col = str[i] == '_' ? 28 :  str[i] - 'a';
            if( trie[v][col] == 0 )  trie[v][col] = ++sz;
            if( i == str.size()-1 ) en[v][col] = id ;
            v = trie[v][col];
        }
    }
    void update(const string& tgt, int par) {
        return update(0, 0, tgt, par);
    }
    void update(int id ,int rt, const string &tgt, int par) {
        if( id == tgt.size() ) return;
        int col = tgt[id] - 'a';
        if( trie[rt][col] ) {
            if(id == tgt.size()-1 && en[rt][col] != par) edg[par].push_back(en[rt][col]);
            update(id+1 , trie[rt][col], tgt, par);
        }
        col = 28;
        if( trie[rt][col] ) {
            if(id == tgt.size()-1 && en[rt][col] != par) edg[par].push_back(en[rt][col]);
            update(id+1 , trie[rt][col], tgt, par);
        }
    }
};

string ara[N];



int main()  {
    // fastio;
    int n, m, k;
    cin>>n>>m>>k;

    Trie trie;

    for(int i = 1; i <= n ; i++ ) {
        string s;
        cin>>s;
        ara[i] = s;
        trie.insert(s, i);
    }
    while(m--) {
        string s ;
        int id;
        cin>>s>>id;

        for(int j = 0 ; j < k ; j++ ) {
            if(ara[id][j] != '_' && ara[id][j] != s[j]) {
                cout<<"NO\n";
                return 0;
            }
        }
        trie.update(s, id);
    }

    // for(int i = 1 ; i <=n ; i++) {
    //     cout<<i<<" -- > ";
    //     for(auto x : edg[i]) cout<<x<<" ";
    //     cout<<'\n';
    // }

    for(int i = 1 ; i <=n ; i++ ) {
        if(vis[i] ==0)  dfs(i);
    }
    if(!ok) cout<<"NO\n";
    else {
        cout<<"YES\n";
        while(!st.empty()) {
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<'\n';
    }

    return 0;
    
}