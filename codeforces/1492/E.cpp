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
int n, m;
vector< vector<int> > vec;

int count_diff(vector<int>&v1, vector<int>&v2) {
    int ret = 0;
    for(int i =0; i < m ; i++) ret += (v1[i] != v2[i]);
    return ret;
}


int solve(int diff) {
    if(diff > 2) return 0;
    
    for(int i =1 ; i < n ; i++ ) {

        int diff_cnt = count_diff(vec[0] , vec[i]);
        if(diff_cnt > 4) return 0;
        if(diff_cnt <= 2) continue;

        for(int j = 0 ; j < m ; j++ ) {
            if(vec[i][j] == vec[0][j]) continue;

            int tmp = vec[0][j];
            vec[0][j] = vec[i][j];

            // for(auto x : vec[0]) cout<<x<<" ";
            // cout<<'\n';
            // cout<<diff_cnt<<'\n';
            int ret = solve(diff+ 1);
            if(ret) return 1;
            vec[0][j] = tmp;
        }
        return 0;
    }
    return 1;
}


int main()  {
    fastio;
    cin>>n>>m;
    vec.resize(n);
    for(int i =0; i <n ; i++) {
        vec[i].resize(m);
        for(int j =0; j < m ;j++) cin>>vec[i][j];
    }
    // cout<<'\n';

    if(solve(0)) {
        cout<<"Yes\n";
        for(auto x : vec[0]) cout<<x<<" ";
        cout<<'\n';
    }
    else cout<<"No\n";
    return 0;

}