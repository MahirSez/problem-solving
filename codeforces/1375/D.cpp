#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int N = 1e6 + 6;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int getMex(vector<int>&vec) {

    int n = vec.size();
    vector<int>rec(n+1);

    for(auto x : vec) rec[x] = 1;

    for(int i =0 ; i <= n ; i++ ) {
        if(rec[i] == 0) return i;
    }
}
int get(vector<int>&vec) {
    int n = vec.size();
    for(int i =0 ; i < n ; i++ ) {
        if(vec[i] != i) return i;
    }
    return -1;
}


int main()
{
    // fastio;

    int t;
    cin>>t;
    while(t-- ){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];

        vector<int>ans;

        // cout<<getMex(vec)<<'\n';

        while(1) {
            
            int mex = getMex(vec);

            // cout<<mex<<'\n';
            if(mex == n) {
                int id = get(vec);
                if(id == -1) break;
                ans.push_back(id);
                vec[id] = mex;
                continue;
            }
            // cout<<mex<<'\n';
            ans.push_back(mex);
            vec[mex] = mex;
        }

        cout<<ans.size()<<'\n';
        for(auto x: ans) cout<<x+1<<" ";
        cout<<'\n';
    }
    return 0;
}