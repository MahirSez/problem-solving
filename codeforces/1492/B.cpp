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

int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>vec(n), taken(n+1), pos(n+1);
        for(int i = 0 ; i < n ; i++) {
            cin>>vec[i];
            pos[vec[i]] = i;
        }
        vector<int>ans;
        for(int i =n ; i >=1 ; i--)  {
            if(taken[i]) continue;
            vector<int>tmp;

            while(1) {
                tmp.push_back(vec.back());
                vec.pop_back();
                taken[tmp.back()] = 1;
                if(tmp.back() == i) break;
            }
            while(tmp.size()) {
                ans.push_back(tmp.back());
                tmp.pop_back();
            }
        }
        for(auto x : ans) cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
}