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
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        vector<int>vec(n), lvl(n+1);
        for(int i =0 ; i < n ; i++) cin>>vec[i];

        int mxlvl = 0;

        int id = 1;
        lvl[0] = 1;

        while(id < n) {
            
            mxlvl++;
            for(int i =0 ; i < lvl[mxlvl-1] && id < n; i++ ) {

                int last = -1;
                while(id < n && vec[id] > last) {
                    lvl[mxlvl]++;
                    last = vec[id];
                    id++;
                }
            }
        }
        cout<<mxlvl<<'\n';
    }
    return 0;
}