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
    int n;
    cin>>n;
    vector<int>vec;

    for(int i = 2 ; i <= n ; i++ ) {
        while(n %i == 0 ) vec.push_back(i) , n/=i;
    }

    int tot = 1;
    for(auto x : vec) tot *= x;
    cout<<tot<<" ";
    for(auto x : vec) {
        tot/=x;
        cout<<tot<<" ";
    }
    cout<<'\n';
    return 0;
}