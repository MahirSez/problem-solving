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
    vector<ll>vec(n+1), sum(n+1);

    for(int i =1; i <=n ; i++) cin>>vec[i];
    sort(vec.begin(), vec.end());

    for(int i =1;i <=n ; i++ ) sum[i] = sum[i-1] + vec[i];
    ll ans = 0;
    int nn = n;
    while(n > 0) {

        int to = nn;
        int frm = to - n ;
        // cout<<to<<" "<<frm<<" "<<n<<'\n';
        ans += sum[to] - sum[frm];
        n/=4;
    }

    cout<<ans<<'\n';
    

    return 0;
}