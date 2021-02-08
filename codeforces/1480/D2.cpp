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

const int N = 1e6 + 6;

int dp[N];
vector<int>vec(N);

vector<int>pos[N];
int n;
int solve(int id) {
    if(id == n) return 0;
    int &ret = dp[id];
    if(ret != -1) return ret;

    ret = solve(id+1);
    auto it = upper_bound(pos[vec[id]].begin() ,pos[vec[id]].end(), id);
    if(*it != n) ret = max(ret ,1 + solve( *it-1));
    return ret;
}

int main()  {
    fastio;

    
    cin>>n;
    
    for(int i =0; i <n ; i++ )cin>>vec[i];
    vector<int>tmp;
    for(int i =0; i< n ; i++ ) {
        if(tmp.size() ==0 || tmp.back() != vec[i]) tmp.push_back(vec[i]);
    }
    
    memset(dp, -1, sizeof dp);
    vec = tmp;
    n = vec.size();

    for(int i =0; i <n ; i++ ) {
        pos[vec[i]].push_back(i);
    }
    for(int i =1 ; i < N ; i++ ) pos[i].push_back(n);

    int ret = solve(0);
    // cout<<ret<<'\n';
    cout<<n-ret<<'\n';




    return 0;
}