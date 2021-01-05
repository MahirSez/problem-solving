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
        int n, m;
        cin>>n>>m;
        vector<int>vec(n), cst(m);
        for(int i = 0 ;i <n ; i++ ) cin>>vec[i], vec[i]--;

        sort(vec.rbegin() , vec.rend());
        for(int i =0;i < m ; i++ ) cin>>cst[i];

        int av = 0;

        ll tot = 0;

        for(auto x : vec) {

            if(av < x) {
                tot += cst[av];

                // cout<<cst[av]<<" ";
                av++;
            }
            else {
                tot += cst[x];
                // cout<<cst[x]<<" ";
            }
        }

        // cout<<'\n';
        cout<<tot<<'\n';

    }
    return 0;
}