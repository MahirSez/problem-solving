#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;
vector<int>edg[N];
int col[N];

int ok;

vector<int>ans[2];

void dfs(int node , int c) {
    
    col[node] = c;
    ans[c].push_back(node);

    for(auto x : edg[node]) {
        if(col[x] == c) ok = 0;
        if(col[x] == -1) dfs(x , c^1);
    }

    

}

int main()  {
    fastio;
    string s;
    cin>>s;
    for(int i =0 ; i <= s.size(); i++ ) {
        string s1 = "";
        string s2 = "";
        for(int j = 0 ;j < i ; j++ ) s1 += s[j];
        for(int j = i; j < s.size() ; j++ ) s2 += s[j];

        for(char ch = 'a' ; ch <='z' ; ch++) {
            string tmp = s1 + ch + s2;
            string tmp1 = tmp;
            reverse(tmp1.begin() , tmp1.end());
            if(tmp  == tmp1) {
                cout<<tmp<<'\n';
                return 0;
            }
        }
    }
    cout<<"NA\n";
    return 0;
}