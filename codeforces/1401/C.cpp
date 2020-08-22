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

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll>vec(n);

        ll mn = INF;
        for(int i =0 ; i < n ; i++) cin>>vec[i] , mn = min(vec[i] , mn);

        vector<int>ids , vals;

        for(int i =0 ; i < n ; i++ ) {
            if(vec[i] % mn == 0) {
                ids.push_back(i);
                vals.push_back(vec[i]);
            }
        }

        sort(vals.begin() , vals.end());

        for(int i =0 ; i < ids.size() ; i++ ) {
            vec[ids[i]] = vals[i];
        }
        int ok = 1;

        for(int i = 0 ; i +1 < n ; i++ ) {
            if(vec[i] > vec[i+1]) ok = 0;
        }

        cout<<(ok? "YES" : "NO")<<'\n';

    }
    return 0;
}